class Solution {
public:
    vector< vector< int > > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='X' || board[r][c]=='Y') return;
        board[r][c]= 'Y';
        for(auto dir: dirs){
            int newx = r+ dir[0];
            int newy = c+ dir[1];
            dfs(board, newx, newy);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int r =board.size();
        if(r==0) return;
        int c = board[0].size();
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                dfs(board, 0, i);
            }
        }
        for(int i=0;i<r;i++){
            if(board[i][c-1]=='O'){
                dfs(board, i, c-1);
            }
        }
        for(int i=c-1;i>=0;i--){
            if(board[r-1][i]=='O'){
                dfs(board, r-1, i);
            }
        }
        for(int i=r-1;i>=0;i--){
            if(board[i][0]=='O'){
                dfs(board, i, 0);
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O') board[i][j]='X';

            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='Y') board[i][j]='O';

            }
        }
    }
};
