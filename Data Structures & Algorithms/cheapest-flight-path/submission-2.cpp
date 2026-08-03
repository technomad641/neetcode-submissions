class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> gr(n);

        for(auto &x: flights){
            gr[x[0]].push_back({x[1], x[2]});
        }

        // {cost, stops, city}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, src});

        // minimum cost to reach city with given stops
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        dist[src][0] = 0;

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int stops = curr[1];
            int city = curr[2];

            if(city == dst)
                return cost;

            if(stops > k)
                continue;

            for(auto &next : gr[city]) {

                int nextCity = next.first;
                int price = next.second;

                if(cost + price < dist[nextCity][stops + 1]) {

                    dist[nextCity][stops + 1] = cost + price;

                    pq.push({
                        cost + price,
                        stops + 1,
                        nextCity
                    });
                }
            }
        }

        return -1;
    }
};