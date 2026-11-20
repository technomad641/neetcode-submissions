class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int startIndex = 0;
        int maxLength = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }


        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (len > maxLength) {
                            maxLength = len;
                            startIndex = i;
                        }
                    }
                }
            }

        }


        return s.substr(startIndex, maxLength);
    }
};