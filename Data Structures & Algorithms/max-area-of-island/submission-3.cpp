class Solution {
public:
    int maxArea = 0;
    void dfs(vector<vector<int>>& grid, int r, int c, int& ans){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
            return;
        }
        ++ans;
        grid[r][c]=0;
        dfs(grid, r-1, c, ans);
        dfs(grid, r+1, c, ans);
        dfs(grid, r, c-1, ans);
        dfs(grid, r, c+1, ans);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        if( r == 0) return maxArea;
        int c = grid[0].size();
        int ans = 0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==1){
                    //++ans;
                    // ans =0;
                    dfs(grid, i , j, ans);
                    maxArea = max(maxArea, ans);
                    ans =0; //reset
                    
                }
            }
        }
        return maxArea;
    }
};
