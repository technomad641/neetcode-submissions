class Solution {
public:
    vector< int > vis;
    vector< int > cyclevis;
    void dfs(vector< vector< int > > &graph, int v){
        vis[v]=2;
        for(auto &x: graph[v]){
            if(vis[x]!=2) dfs(graph, x);
        }
    }
    bool isCycle(vector< vector< int > > &graph, int v){
        cyclevis[v] = 2; // within call stack
        for(auto &nei: graph[v]){
            if(cyclevis[nei]==2) return true;
            else if(isCycle(graph, nei)) return true;
        }
        cyclevis[v] = 1; // out of stack now
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vis.resize(N, 0);
        cyclevis.resize(N, 0);
        vector< int > ans;
        vector< vector< int > > newgr(N);
        //  for(int i=0;i< N;i++){
        //     for(auto &x: graph[i]){
        //         newgr[x].push_back(i);
        //     }
        //  }
        for(int i =0;i< N;i++){
            if(vis[i]==0 && !isCycle(graph, i)){
                ans.push_back(i);
            }
        }
        // for(int i=0;i<N;i++){
        //     if(vis[i]==1) ans.push_back(i);
        // }
        return ans;
    }
};
