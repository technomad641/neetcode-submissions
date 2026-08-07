class Solution {
public:
    bool dfs(vector<vector<int>>& gr, vector<int>&vis, vector<int>&ans, int x){
        vis[x]=1;
        for(auto nei: gr[x]){
            if(vis[nei]==0){
                if(dfs(gr, vis, ans, nei)) return true;
            }else if(vis[nei]==1) return true;
        }
        vis[x]=2;
        ans.push_back(x);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int > >gr(numCourses);
        for(auto x:prerequisites ){
            gr[x[1]].push_back(x[0]);
        }
        vector< int > ans;
        vector< int > vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(gr, vis, ans, i)){
                    ans.clear(); break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
