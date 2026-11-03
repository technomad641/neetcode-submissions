class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int ans = 0;
        int maxArea = INT_MIN;
        while(i<=j){
            ans =(j-i)*min(heights[i], heights[j]);
            if(heights[i]<heights[j]) i++;
            else --j;
            maxArea = max(maxArea, ans);
        }
        return maxArea;
    }
};
