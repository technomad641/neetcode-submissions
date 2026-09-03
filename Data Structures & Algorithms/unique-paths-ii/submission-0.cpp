class Solution {
public:
    vector< vector<int >>dp;
    int recur(int m , int n, vector<vector<int>>& obstacleGrid){
        if(m< 0 || n<0) return 0;
        if(obstacleGrid[m][n]==1) return 0;
        if(m==0 && n ==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        return  dp[m][n]=recur(m-1, n,obstacleGrid)+recur(m,n-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
         if(m==0) return 0;
         int n = obstacleGrid[0].size();
         dp = vector< vector<int >>(m+1, vector<int>(n+1, -1));
         
        
        return recur(m-1 ,n-1, obstacleGrid);
    }
};