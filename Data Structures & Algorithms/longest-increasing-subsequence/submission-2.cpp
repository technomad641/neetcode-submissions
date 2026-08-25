class Solution {
public:
    map< int, map<int, int>> dp;
    int recur(int last, vector<int>& nums, int index){
        if(index==nums.size()) return 0;
        if(dp.find(index)!= dp.end() && dp[index].find(last)!= dp[index].end()) return dp[index][last];
        int include =0;
        if(last< nums[index]){
            include = recur(nums[index], nums, index+1)+1;
        }
        int exclude = recur(last, nums, index+1);
        return dp[index][last]= max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        return recur(INT_MIN, nums, 0);
    }
};
