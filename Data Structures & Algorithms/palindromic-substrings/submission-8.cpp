class Solution {
public:
    int dp[1000][1001];
    int ispalin(int x , int y, string &s){
        if(dp[x][y]!= -1) return dp[x][y];
        if(y-x <2) return dp[x][y] = s[x]==s[y];
        return dp[x][y] = s[x]==s[y] && ispalin(x+1, y-1, s);
    }
    int countSubstrings(string s) {
         int sz = s.length();
        for(int i=0;i<sz;i++){
             for(int j=0;j<sz;j++){
                    dp[i][j]= -1;
             }
        }
        int cnt = 0;
       
        for(int i=0;i<sz;i++){
             for(int j=i;j<sz;j++){
                if(ispalin(i, j, s)){
                    ++cnt;
                }
             }
        }
        return cnt;
    }
};
