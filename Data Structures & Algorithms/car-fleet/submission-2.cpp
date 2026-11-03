
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> dis;

        int sz = position.size();

        for(int i = 0; i < sz; i++) {
            double time = (double)(target - position[i]) / speed[i];
            dis.push_back({position[i], time});
        }

        // Sort by position descending
        sort(dis.rbegin(), dis.rend());

        int ans = 0;
        stack<double> st;

        for(int i = 0; i < sz; i++) {

            if(st.empty()) {
                st.push(dis[i].second);
            }
            else {
                if(st.top() >= dis[i].second)
                    continue;
                else
                    st.push(dis[i].second);
            }
        }

        return st.size();
    }
};
