class Solution {
public:
    vector<vector<int>> dp;
    int topDown(int i, int prev_idx, vector<int>& nums){
        if(i < 0) return 0;
        if(dp[i][prev_idx] != -1) return dp[i][prev_idx];
        int take = (prev_idx == nums.size() || nums[i] < nums[prev_idx]) ? (topDown(i-1, i, nums) + 1) : 0;
        int skip = topDown(i-1, prev_idx, nums);
        return dp[i][prev_idx] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size(), vector<int>(nums.size() + 1, -1));
        return topDown(nums.size()-1, nums.size(), nums);
    }
};
