class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int cnt = 0;

        if (intervals.size() == 0) return 0;

        for (auto x : intervals) {
            while(!pq.empty() && pq.top()[0]<=x.start){
                pq.pop();
            }
            pq.push({x.end, x.start});
            cnt = max(cnt, (int)pq.size());
        }

        return cnt;
    }
};