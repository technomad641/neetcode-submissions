
class Solution {
public:
    void dfs(vector<vector<int>>&gr, vector< int > &vis, int i, int N){
            //if(vis[i]==1) return;
            vis[i]=1;
            for(auto x: gr[i]){
                if(!vis[x]){
                    //vis[x]=1;
                     dfs(gr, vis, x, N);
                }
            }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans =0;
        vector< int > vis(n , 0);

        vector< vector< int > > gr(n);
        for(auto x: edges){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(gr, vis, i, n);
                ++ans;
            }
        }
        
        return ans;
    }
};
