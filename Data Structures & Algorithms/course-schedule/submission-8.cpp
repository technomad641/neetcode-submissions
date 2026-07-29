class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< int > indeg(numCourses, 0);
        vector< vector< int > > gr(numCourses);
        for(auto x:prerequisites){
            indeg[x[1]]++;
            gr[x[0]].push_back(x[1]);
        }
        queue< int > Q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] ==0){
                Q.push(i);
            }
        }
        while(!Q.empty()){
            auto x = Q.front(); Q.pop();
            for(auto p:gr[x]){
                indeg[p]--;
                if(indeg[p]==0) Q.push(p);
            }
            
        }
        for(int i=0;i<numCourses;i++){
            if(indeg[i]!=0) return 0;
        }
        return 1;
    }
};
