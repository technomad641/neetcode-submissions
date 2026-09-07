class Solution {
public:
    vector< int > vis;
    vector< int > indeg;
    bool isCycle(int sz, vector< vector< int > >&gr){
        queue< int > q;
        for(int i=0;i<sz;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(auto l: gr[p]){
                indeg[l]--;
                if(indeg[l]==0) q.push(l);
            }
        }
        for(int i=0;i<sz;i++){
            if(indeg[i]>0) return true;
        }
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int > >gr(numCourses);
        //vis.resize(numCourses, 0);
        indeg.resize(numCourses, 0);
        for(auto x: prerequisites){
            gr[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        //for(int i=0;i<numCourses;i++){
        if(isCycle(numCourses, gr)) return false;
        //}   
        return true;
    }
};
