class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int startR = 0;
        int endR = matrix.size() - 1;
        int startC = 0;
        int endC = matrix[0].size() - 1;

        vector<int> ans;

        while (startR <= endR && startC <= endC) {

            // Top row
            for (int i = startC; i <= endC; i++) {
                ans.push_back(matrix[startR][i]);
            }
            ++startR;

            // Right column
            for (int i = startR; i <= endR; i++) {
                ans.push_back(matrix[i][endC]);
            }
            --endC;

            // Bottom row
            if (startR <= endR) {
                for (int i = endC; i >= startC; i--) {
                    ans.push_back(matrix[endR][i]);
                }
                --endR;
            }

            // Left column
            if (startC <= endC) {
                for (int i = endR; i >= startR; i--) {
                    ans.push_back(matrix[i][startC]);
                }
                ++startC;
            }
        }

        return ans;
    }
};