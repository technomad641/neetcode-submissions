class Solution {
public:
    vector< vector< pair<int, int> > >gr;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        gr =vector< vector< pair<int, int> > >(1001, vector<pair<int, int>>());
        int sz = times.size();
        for(int i=0;i<sz;i++){
            gr[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        //int total_edge = n-1;
        vector< int >dis(1001, INT_MAX);
        dis[k]=0;
        int ans = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>> , greater< pair<int, int> > > pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            for(auto nei: gr[x.second]){
                if(dis[x.second]+ nei.first < dis[nei.second]){
                    dis[nei.second]= dis[x.second]+ nei.first;
                    pq.push({dis[nei.second],nei.second });
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
        
    }
};
