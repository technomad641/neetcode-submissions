class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair<int, double > >dis;
        int sz = position.size();
        for(int i=0;i<sz;i++){
            double time = target -position[i];
            time/=speed[i];
            dis.push_back({position[i], time});
        }
        sort(rbegin(dis), rend(dis));
        int ans = 0;
        stack< double > st;
        for(int i=0;i<sz;i++){
            if(i==0){
                st.push(dis[i].second);
            }
            else{
                if(!st.empty() && st.top()>=dis[i].second) continue;
                else  st.push(dis[i].second);
            }
        }
        return st.size();
    }
};
