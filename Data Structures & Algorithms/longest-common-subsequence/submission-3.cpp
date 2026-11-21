class Solution {
public:
    vector< vector< int > > dp;
    int topDown(int i, int j, string &A, string &B){
        if(i< 0 || j< 0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int z = 0;
        if(A[i]==B[j]){
            z = 1 + topDown(i-1, j-1, A, B);
        }
        int x = topDown(i-1, j, A, B);
        int y = topDown(i, j-1, A, B);
        int p = topDown(i-1, j-1, A, B);
        return dp[i][j]=max(max(x, y), max(z, p));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int sz1= text1.length();
        int sz2= text2.length();
        dp.resize(sz1+1, vector<int>(sz2+1, -1));
        return topDown(sz1-1,sz2-1, text1, text2);
    }
};
