class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(102, vector<double>(102, 0.0));
        dp[0][0] = poured;

        for (int row = 0; row < query_row; row++) {
            for (int glass = 0; glass <= row; glass++) {
                double overflow = max(0.0, dp[row][glass] - 1.0);

                dp[row + 1][glass] += overflow / 2.0;
                dp[row + 1][glass + 1] += overflow / 2.0;
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};