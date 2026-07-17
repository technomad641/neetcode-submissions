class Solution {
public:
    void bfs(queue< vector<int> >&Q, int &T, int R, int C, vector<vector<int>>& grid,map< vector< int >, int >&vis){
        
        --T;
        while(!Q.empty()){
            int sz = Q.size();
            T++;
            for(int i=0;i<sz;i++){
                auto x = Q.front(); Q.pop();
                int r = x[0];
                int c = x[1];
                if(r-1>=0 && vis.find({r-1, c})==vis.end() && grid[r-1][c]==1){
                        vis[{r-1, c}]=1;
                        grid[r-1][c] =2;
                        Q.push({r-1, c});
                }
                if(c-1>=0 && vis.find({r, c-1})==vis.end()&& grid[r][c-1]==1){
                        vis[{r, c-1}]=1;
                        grid[r][c-1] =2;
                        Q.push({r, c-1});
                }
                if(r+1<R && vis.find({r+1, c})==vis.end()&& grid[r+1][c]==1){
                        vis[{r+1, c}]=1;
                        grid[r+1][c] =2;
                        Q.push({r+1, c});
                }
                if(c+1<C && vis.find({r, c+1})==vis.end()&& grid[r][c+1]==1){
                        vis[{r, c+1}]=1;
                        grid[r][c+1] =2;
                        Q.push({r, c+1});
                }
            }
        }
       // --T;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue< vector<int> > Q;
        int r =grid.size();
        if(r==0) return -1;
        int T=0;
        map< vector< int >, int > vis;
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    //T=1;
                    vis[{i, j}]=1;
                    Q.push({i, j});
                }
            }
        }
        
        if(!Q.empty()) {
            //++T;
            bfs(Q, T, r ,c, grid, vis);
            //return T-1;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return T;
    }
};
