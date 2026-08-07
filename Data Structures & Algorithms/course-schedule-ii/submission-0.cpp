class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int > >gr(numCourses);
        for(auto x:prerequisites ){
            gr[x[1]].push_back(x[0]);
        }
        vector< int >indeg(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto p: gr[i]){
                indeg[p]++;
            }
        }
        vector<int>ans;
        deque< int > Q;
        for(int i=0;i<numCourses;i+=1){
            if(indeg[i]==0){
                Q.push_back(i);
            }
        }
        while(!Q.empty()){
            int x = Q.front(); Q.pop_front();
            ans.push_back(x);
            //vis[x]=1;
            for(auto nei: gr[x]){
               // if(!vis[nei]){
                    indeg[nei]--;
                    if(indeg[nei]==0) Q.push_back(nei);
               // }
            }
        }
        for(int i=0;i<numCourses;i+=1){
            if(indeg[i]>0){
                ans.clear(); 
                break;
            }
        }
        return ans;
    }
};
