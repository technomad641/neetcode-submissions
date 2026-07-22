class Solution {
public:
map< int, int > dp;
    int maxrob(vector<int>& nums, int i){
        if(i>=nums.size()) return 0;
        if(dp.find(i)!= dp.end()) return dp[i];
        // rob ith house
        int L= nums[i] + maxrob(nums, i+2);
        // skip ith house
        int R = maxrob(nums, i+1);
        return dp[i]= max(L, R);
    }
    int rob(vector<int>& nums) {
        return maxrob(nums, 0);
        
    }
};
