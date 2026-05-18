class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sz = nums.size();
        int l = 0;
        int S = 0;
        for(int r =0;r< sz;r++){
            S+=nums[r];
            while(S>=target && l<=r){
                ans = min(ans, r-l+1);
                S-=nums[l];
                ++l;
            }
        }
        return ans ==INT_MAX ? 0: ans;
    }
};