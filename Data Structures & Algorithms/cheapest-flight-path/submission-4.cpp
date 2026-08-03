class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< int > dis(n, INT_MAX);
        dis[src] =0;
        vector< vector< pair<int, int> > >gr(n);
        for(auto x: flights){
            gr[x[0]].push_back({x[1], x[2]});
        }
        queue< vector< int> >PQ;
        PQ.push({0, 0, src});
        while(!PQ.empty()){
            vector< int > K = PQ.front(); PQ.pop();
            int currhop = K[2]; // current city
            int cost = K[1];
            if(K[0]>k) continue;
            for(auto x: gr[currhop]){
                    if(x.second+ cost < dis[x.first]){
                       // if(hopleft<=k+1){
                            dis[x.first] = x.second+ cost;
                            PQ.push({K[0]+1, dis[x.first], x.first}); 
                       // }
                        
                }
            }  

        }
        return dis[dst] ==INT_MAX ? -1 : dis[dst];

    }
};
