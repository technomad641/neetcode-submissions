class Solution {
public:
    vector< int > dp;
    int topDown(int index, vector<int>& nums){
        if(index >= nums.size()) return dp[index]=0;
        if(dp[index]!= -1) return dp[index];
         int take = topDown(index+2, nums) + nums[index];
        int skip = topDown(index+1, nums);
        return dp[index]=max(take, skip);
    }
    int rob(vector<int>& nums) {
        dp.resize(200, -1);
        return topDown(0, nums);
    }
};
