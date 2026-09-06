class Solution {
public:
    unordered_map< int , unordered_map< int , int > > dp;
    int recur(string a, int i, string b, int j){
        if(i< 0 || j< 0) return dp[i][j]=0;
        if(dp.find(i)!= dp.end() && dp[i].find(j)!= dp[i].end()) return dp[i][j];
        int ans = 0;
        if(a[i]==b[j]){
            ans = 1+ recur(a, i-1, b, j-1);
        }
        ans = max(ans, recur(a, i-1, b, j));
        ans = max(ans, recur(a, i, b, j-1));
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int sz1 = text1.length();
         int sz2 = text2.length();
         return recur(text1, sz1-1, text2, sz2-1);
    }
};
