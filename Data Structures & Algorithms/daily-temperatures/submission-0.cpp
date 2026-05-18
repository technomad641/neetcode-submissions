class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        pair< int, int > PP;
        stack<pair<int,int>>st;
        int sz = temperatures.size();
        vector< int > ans(sz, 0);
        for(int i=0;i<sz;i++){
            if(st.empty()){
                st.push(make_pair(temperatures[i], i));
            }else{
                while(!st.empty() && temperatures[i]> st.top().first){
                        auto N = st.top();
                        ans[N.second] = -N.second+i;
                        st.pop();
                }
                st.push(make_pair(temperatures[i], i));
            }
        }
        while(!st.empty() && temperatures[sz-1]> st.top().first){
                        auto N = st.top();
                        ans[N.second] = -N.second+sz-1;
                        st.pop();
                }
        return ans;
    }
};
