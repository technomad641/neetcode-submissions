class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<pair<int, int>> interval;

        for (auto &x : intervals) {
            interval.push_back({x.end, x.start});
        }

        // IMPORTANT: sort by START time, not end time
        sort(interval.begin(), interval.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second < b.second;
            });

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > PQ;

        int ans = 0;

        for (int i = 0; i < interval.size(); i++) {

            while (!PQ.empty()) {
                auto z = PQ.top();

                // Previous meeting has ended
                if (interval[i].second >= z.first)
                    PQ.pop();
                else
                    break;
            }

            PQ.push(interval[i]);

            ans = max(ans, (int)PQ.size());
        }

        return ans;
    }
};