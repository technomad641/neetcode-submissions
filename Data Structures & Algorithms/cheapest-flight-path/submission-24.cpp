class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector< vector<pair< int, int >> > gr(n);
        vector< int> dis(n, INT_MAX);
        queue< pair< int, int > > Q;
         vector< int> vis(n, 0);

        int total_hops = k+1;
        dis[src] =0;

        Q.push({src, dis[src]});
        for(auto &flight: flights){
            gr[flight[0]].push_back({flight[1], flight[2]});
        }
        for(int i=1;i<=total_hops;i++){
            int sz = Q.size();
            for(int j=0;j<sz;j++){
                pair< int, int >  p = Q.front(); Q.pop();
                for(auto x: gr[p.first]){
                    //dis[x.first] = min(x.second + p.second, dis[x.first]);
                   
                    if(dis[x.first] > (x.second + p.second)){
                        dis[x.first] = x.second + p.second;
                         Q.push({x.first, dis[x.first]});
                    }
                } 
            }
        }
        
        return dis[dst] == INT_MAX  ? -1: dis[dst];
    }
};
