class Solution {
public:
    vector< int > cyclevis;
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
        cyclevis.resize(N, 0);
        vector< int > ans;
        for(int i =0;i< N;i++){
            if(!isCycle(graph, i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
