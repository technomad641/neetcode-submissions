class Solution {
public:
    vector< vector< int > > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int r, int c){
        //if(r<0 || r>=grid.size() || c< 0 || c>= grid[0].size()) return;
        //if(grid[r][c]=='0') return;
        grid[r][c] = '0';
        for(auto dir: dirs){
            int newx = dir[0] + r;
            int newy = dir[1] + c;
            if(newx<0 || newx>=grid.size() || newy< 0 || newy>= grid[0].size()) continue;
            if(grid[newx][newy]=='1') dfs(grid, newx, newy);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if(r ==0) return 0;
        int c = grid[0].size();
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
