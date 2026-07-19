class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< int> indegree(numCourses, 0);
        vector< int> vis(numCourses, 0);
        vector < vector< int  > > gr(numCourses);
        for(auto x:prerequisites){
            indegree[x[1]]++;
            gr[x[0]].push_back(x[1]);
        }
        queue< int > Q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                Q.push(i);
                vis[i]=1;
             }
        }
        while(!Q.empty()){
                int x = Q.front(); Q.pop();
                for(auto y: gr[x]){
                    //if(!vis[y]){
                       //vis[y]=1;
                        indegree[y]--;
                        if(indegree[y]==0) Q.push(y);
                                          }
                //}
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]!=0) return false;
        }
        return true;

    }
};
