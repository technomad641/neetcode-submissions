class Solution {
public:
    map< int, int > dp;
    int tribonacci(int n) {
        if(n ==0) return dp[0]= 0;
        if(n==1) return dp[n]=1;
        if(n==2) return dp[n]=1;
        if(dp.find(n)!= dp.end()) return dp[n];
        return dp[n] = tribonacci(n-2) + tribonacci(n-1) + tribonacci(n-3);

        
    }
};