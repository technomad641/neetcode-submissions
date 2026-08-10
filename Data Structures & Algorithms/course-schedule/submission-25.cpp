class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< int > indeg(numCourses, 0);
        vector< vector< int > > graph(numCourses);
        for(auto gr:prerequisites){
            indeg[gr[0]]++;
            graph[gr[1]].push_back(gr[0]);
        }
        deque< int > dq;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) dq.push_back(i);
        }
        int cnt = 0;
        while(!dq.empty()){
            int  p= dq.front(); dq.pop_front();
             ++cnt;
            for(auto nei: graph[p]){
                indeg[nei]--;
                if(indeg[nei]==0) dq.push_back(nei);
            }
        }
        return cnt ==numCourses;

    }
};
