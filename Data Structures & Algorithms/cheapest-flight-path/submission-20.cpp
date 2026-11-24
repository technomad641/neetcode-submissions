class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        const int INF = INT_MAX;
        vector<int> dist(n, INF);
        dist[src] = 0;

        // k stops allow at most k + 1 flights.
        for (int flightsUsed = 0; flightsUsed <= k; ++flightsUsed) {
            vector<int> nextDist = dist;

            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (dist[from] == INF) {
                    continue;
                }

                nextDist[to] = min(
                    nextDist[to],
                    dist[from] + price
                );
            }

            dist = move(nextDist);
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};