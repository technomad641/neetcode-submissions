class Solution {
public:
    vector< vector< int > >dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    bool dfs(vector<vector<char>>& board, int r, int c, int index , string word){
        if(board[r][c]!= word[index]) return false;
        if(index == word.size()-1) return  board[r][c] == word[index];
        //if(index>=word.size()) return false;
        char temp = board[r][c];
        board[r][c]= '.';
        for(auto dir: dirs){
            int newr = dir[0]+ r;
            int newc = dir[1]+ c;
            if(newr<0 || newc<0 || newr>=board.size() || newc>=board[0].size()) continue; // out of bounds to never check this please
            if(board[newr][newc] != '.' && dfs(board, newr, newc, index+1, word)) return true;
        }
        board[r][c] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        if(r==0) return true;
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }
};
