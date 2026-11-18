class Solution {
public:
    map< int, map<int, int> > dp;
    int topDown(int index, int prev, vector<int>& nums){
        if(index == nums.size()){
            return 0;
        }
        if(dp[index].find(prev)!= dp[index].end()) return dp[index][prev];
        // take case
        int take = nums[index]>prev? 1+ topDown(index+1, nums[index], nums):0;
        int skip = topDown(index+1, prev, nums);
        dp[index][prev] = max(take, skip);
        return dp[index][prev];
    }
    int lengthOfLIS(vector<int>& nums) {
        return topDown(0,-2000 , nums);
    }
};
