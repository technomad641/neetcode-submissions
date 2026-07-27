class Solution {
public:
    map<int, int>dp;
    int climbStairs(int n) {
        if(n<=0) return dp[n]=0;
        if(n==1) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp.find(n)!= dp.end()) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
