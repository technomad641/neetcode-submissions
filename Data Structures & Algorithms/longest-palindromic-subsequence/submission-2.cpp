class Solution {
public:
    unordered_map< int, unordered_map< int, int > > dp;
    int recur(int i, int j, string s){
        if(i>j) return 0;
        if(i==j) return dp[i][j]=1;
        if(s[i]==s[j]) return dp[i][j]=2+recur(i+1, j-1, s);
        if(dp.find(i)!=dp.end() && dp[i].find(j)!= dp[i].end()){
            return dp[i][j];
        }
        return dp[i][j] = max(recur(i+1, j, s), recur(i, j-1, s));
    }
    int longestPalindromeSubseq(string s) {
        int sz = s.length();
        int maxlen =0;
        // for(int i=0;i<sz;i++){
        //     int ans =1;
        //     for(int j=i;j<sz;j++){
        //         if(s[i]==s[j]){
        //             ans = 2 + recur(i+1, j-1, s);
        //         }else{
        //             ans = max(recur(i+1, j, s), recur(i, j-1, s));
        //         }
        //         dp[i][j]= ans;
        //         maxlen = max(maxlen, dp[i][j]);
        //     }
        // }
        return recur(0, sz-1, s);
    }
};