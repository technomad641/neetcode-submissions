class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool checkPacific(vector<vector<int>>& heights,
                      vector<vector<int>>& vis,
                      int r, int c, int R, int C) {

        vis[r][c] = 1;

        for (auto &x : dir) {
            int newR = r + x[0];
            int newC = c + x[1];

            if ((newR == -1 && newC >= 0 && newC < C) ||
                (newC == -1 && newR >= 0 && newR < R))
                return true;

            if (newR < 0 || newC < 0 || newR >= R || newC >= C)
                continue;

            if (!vis[newR][newC] &&
                heights[newR][newC] <= heights[r][c]) {
                if (checkPacific(heights, vis, newR, newC, R, C))
                    return true;
            }
        }

        return false;
    }

    bool checkAtlantic(vector<vector<int>>& heights,
                       vector<vector<int>>& vis,
                       int r, int c, int R, int C) {

        vis[r][c] = 1;

        for (auto &x : dir) {
            int newR = r + x[0];
            int newC = c + x[1];

            if ((newR == R && newC >= 0 && newC < C) ||
                (newC == C && newR >= 0 && newR < R))
                return true;

            if (newR < 0 || newC < 0 || newR >= R || newC >= C)
                continue;

            if (!vis[newR][newC] &&
                heights[newR][newC] <= heights[r][c]) {
                if (checkAtlantic(heights, vis, newR, newC, R, C))
                    return true;
            }
        }

        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        vector<vector<int>> ans;

        if (R == 0)
            return ans;

        int C = heights[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                vector<vector<int>> visPacific(R, vector<int>(C, 0));
                if (!checkPacific(heights, visPacific, i, j, R, C))
                    continue;

                vector<vector<int>> visAtlantic(R, vector<int>(C, 0));
                if (checkAtlantic(heights, visAtlantic, i, j, R, C))
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};