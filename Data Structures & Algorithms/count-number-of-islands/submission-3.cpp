class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || c< 0 || r>=grid.size() || c>=grid[0].size()) return;
        if(grid[r][c]=='0') return;
        grid[r][c]='0';
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
    }
    vector< vector< int > > dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue< pair< int , int> > Q;
        Q.push({r, c});
        while(!Q.empty()){
            pair< int, int > F = Q.front(); Q.pop();
            grid[F.first][F.second] = '0';
            for(auto x: dir){
                int newx = F.first + x[0];
                int newy = F.second + x[1];
                if(newx>=0 && newx<grid.size() && 
                newy>=0 && newx<grid[0].size()){
                    Q.push({newx, newy});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int r = grid.size();
        if(r == 0) return 0;
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
