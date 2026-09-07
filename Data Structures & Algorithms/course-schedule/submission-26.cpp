class Solution {
public:
    vector< int > vis;
    bool isCycle(int node, vector< vector< int > >&gr){
        vis[node]= 1;
        for(auto x: gr[node]){
            if(vis[x]==1) return true;
            if(vis[x]==2) continue;
            if(isCycle(x, gr)) return true;
        }
        vis[node]=2;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int > >gr(numCourses);
        vis.resize(numCourses, 0);
        for(auto x: prerequisites){
            gr[x[0]].push_back(x[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(isCycle(i, gr)) return false;
        }
        return true;
    }
};
