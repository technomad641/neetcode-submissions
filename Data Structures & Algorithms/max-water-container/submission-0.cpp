class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int sz = heights.size();;
        int ans = INT_MIN;
        while(l<r && l< sz && r>=0){
            int dis = r-l;
            if(heights[l]<heights[r]){
                ans = max(ans, min(heights[r],heights[l])*dis);
                l++;
            }else{
                ans = max(ans, min(heights[l],heights[r])*dis);
                r--;
            }
            // ans = max(ans , max(heights[l], heights[r])*dis);
            // if(heights[l]>heights[r]) r--;
            // else l++;
        }
        return ans;
    }
};


//  1 7 2 5 4 7 3 6
//  0 1 2 3 4 5 6 7

//  6*6 = 36