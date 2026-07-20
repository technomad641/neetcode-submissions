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


        queue< pair< int, int > > Q;
        //vis[0]=1;
        Q.push({0, -1});
        while(!Q.empty()){
            auto S = Q.front();Q.pop();
            vis[S.first]=1;
            for(auto x: gr[S.first]){
                if(!vis[x]){
                    Q.push({x, S.first});
                }else if(x!= S.second) return 0;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return 0;
        }
        return 1;
    }
};