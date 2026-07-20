class Solution {
public:
    bool isCycle(vector<vector<int>>& gr, vector<int>& vis, int node) {
        vis[node] = 1;   // currently visiting

        for (auto v : gr[node]) {
            if (vis[v] == 0) {
                if (isCycle(gr, vis, v))
                    return true;
            }
            else if (vis[v] == 1) {
                return true;
            }
        }

        vis[node] = 2;   // completely processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        vector<int> vis(numCourses, 0);

        for (auto x : prerequisites) {
            gr[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (isCycle(gr, vis, i))
                    return false;
            }
        }

        return true;
    }
};