class Solution {
public:
    vector< vector<int >>dp;
    int recur(int m , int n){
        if(m==0 && n ==0) return 1;
        if(m< 0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        return  dp[m][n]=recur(m-1, n)+recur(m,n-1);
    }
    int uniquePaths(int m, int n) {
        dp = vector< vector<int >>(m+1, vector<int>(n+1, -1));
        return recur(m-1 ,n-1);
    }
};
