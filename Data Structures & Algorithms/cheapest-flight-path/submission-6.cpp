class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< int > dis(n+1, INT_MAX);
        dis[src] =0;
        vector< vector< pair<int,int> > >gr(n+1);
        for(auto x: flights){
            gr[x[0]].push_back({x[1], x[2]});
        }
        deque< vector< int > > Q;
        Q.push_back({0, src, dis[src]});
        while(!Q.empty()){
            int sz = Q.size();
            for(int i=0;i<sz;i++){
                auto P = Q.front(); Q.pop_front();
                if(P[0]==k+1) continue;
                for(auto g: gr[P[1]]){
                     int nextNode = g.first;
                     int distance = g.second;
                     if(dis[nextNode]> distance+ P[2]){
                        dis[nextNode]= distance+ P[2];
                        Q.push_back({P[0]+1, nextNode, dis[nextNode] });
                     }
                }
            }
        }

        return dis[dst] == INT_MAX ? -1: dis[dst];
    }
};