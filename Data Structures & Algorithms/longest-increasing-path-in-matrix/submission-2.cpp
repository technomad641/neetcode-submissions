class Solution {
public:
    vector< vector< int > > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> vis;
    bool valid(int i, int j, int x, int y, vector<vector<int>>& matrix){
         if(x<0 || y< 0 || x>=matrix.size() || y>=matrix[0].size()) return false;
         return matrix[i][j] > matrix[x][y];
    }
    int dfs(int i, int j, vector<vector<int>>& matrix){
        if(i<0 || j< 0 || i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(vis[i][j]>0) return vis[i][j];
        int ans = 1;
        for(auto &dir : dirs){
            int newx = i + dir[0];
            int newy = j + dir[1];
            if(valid(i, j, newx, newy, matrix)){
                ans = max(ans,1+dfs(newx, newy, matrix));
            }
        }
        return vis[i][j] =ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if( r ==0) return 0;
        int c = matrix[0].size();

         for(int i=0;i<r;i++){
            vector< int > p;
            for(int j=0;j<c;j++){
                p.push_back(0);
            }
            vis.push_back(p);
            p.clear();
        }
        
        int max_ans = 1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0){
                    max_ans = max(max_ans, dfs(i, j, matrix));
                }
            }
        }
        return max_ans;
    }
};
