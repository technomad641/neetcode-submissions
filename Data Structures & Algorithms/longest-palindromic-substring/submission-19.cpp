class Solution {
public:
    int dp[1001][1001];

    int ispalin(int x, int y, const string& s) {
        if (dp[x][y] != -1)
            return dp[x][y];

        if (y - x < 2)
            return dp[x][y] = (s[x] == s[y]);

        return dp[x][y] =
            (s[x] == s[y] && ispalin(x + 1, y - 1, s));
    }

    string longestPalindrome(string s) {
        int sz = s.length();

        if (sz <= 1)
            return s;

        // Initialize DP
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                dp[i][j] = -1;
            }
        }

        int ans = 1;
        int st = 0;

        for (int i = 0; i < sz; i++) {
            for (int j = sz - 1; j >= i; j--) {

                if (ispalin(i, j, s)) {
                    if (ans < j - i + 1) {
                        ans = j - i + 1;
                        st = i;
                        break;
                    }
                }
            }
        }

        return s.substr(st, ans);
    }
};