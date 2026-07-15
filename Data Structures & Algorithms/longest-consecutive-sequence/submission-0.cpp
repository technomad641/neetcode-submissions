class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map< int , int > dp;
        sort(begin(nums), end(nums));
        int ans = 0;
        //for(auto x: nums) dp[x]++;
        for(auto x: nums){
            dp[x] = max(dp[x], dp[x-1]+1);
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};
