class Solution {
public:
    bool iscycleC(vector<vector<int>>& gr, vector<int>& vis, int x, int parent) {
        vis[x] = 1;

        for (auto v : gr[x]) {
            if (!vis[v]) {
                if (iscycleC(gr, vis, v, x))
                    return true;
            }
            else if (v != parent) {
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> gr(n);

        for (auto &x : edges) {
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }

        if (iscycleC(gr, vis, 0, -1))
            return false;

        // Ensure the graph is connected.
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};