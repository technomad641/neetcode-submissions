class Solution {
public:
     vector<vector<int>> dp = vector<vector<int>>(201, vector<int>(201, -1));
    int recur(vector<vector<int>>& grid, int m, int n){
        //cout<< m<<" "<<n<<" ";
        if(m <0 || n<0) return 10001;
        if(m==0 && n==0) return dp[m][n]=grid[0][0];
        if(dp[m][n]!= -1) return dp[m][n];
        //int option1 = grid[m][n]+ recur(grid, m-1, n);
        //int option2 = grid[m][n]+ recur(grid, m, n-1);
        //cout<<grid[m][n] + min(option1, option2)<<endl;
        return dp[m][n]= grid[m][n]+min(recur(grid, m-1, n), recur(grid, m, n-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        return recur(grid, m, n);
    }
};