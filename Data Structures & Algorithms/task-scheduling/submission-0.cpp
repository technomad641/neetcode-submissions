class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) freq[c]++;

        priority_queue<int> pq; // max-heap of remaining counts
        for (auto &kv : freq) pq.push(kv.second);

        queue<pair<int,int>> cooldown; // (readyTime, remainingCount)
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // Release ALL tasks whose cooldown has finished
            while (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            // Execute one task if available
            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                cnt--; // run it once

                if (cnt > 0) {
                    // next time this task can be scheduled again
                    cooldown.push({time + n + 1, cnt});
                }
            }
            // else: idle
        }

        return time;
    }
};