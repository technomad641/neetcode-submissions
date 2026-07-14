class Solution {
public:
    void dfs(vector<vector<char>>& grid, 
    vector<vector<bool>>& vis, int r, int c) {
        if(vis[r][c]) return;
        vis[r][c]=true;
        if(r-1>=0 && grid[r-1][c]=='1'){
            dfs(grid, vis, r-1, c);
        }
        if(r+1<grid.size() && grid[r+1][c]=='1'){
             dfs(grid, vis, r+1, c);
        }
        if(c-1>=0 && grid[r][c-1]=='1'){
             dfs(grid, vis, r, c-1);
        }
        if(c+1<grid[0].size() && grid[r][c+1]=='1'){
             dfs(grid, vis, r, c+1);
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int cnt = 0;
        if(r ==0) return 0;
        int c = grid[0].size();
        vector< vector< bool > > vis(r);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) 
                vis[i].push_back(false);
        }
        for(int i=0;i< r;i++){
            for(int j=0;j< c;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ++cnt;
                    dfs(grid, vis, i , j);
                }
            }
        }
        return cnt;
    }
};
