class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int sz = temperatures.size();
        vector<int> ans;
        ans.resize(sz, 0);
        stack< int > st;
        for(int i=0;i<sz;i++){
            if(st.empty() || temperatures[i]< temperatures[st.top()]) st.push(i);
            else{
                while(!st.empty() && temperatures[i]> temperatures[st.top()]){
                    int k = st.top(); 
                    ans[k] = i-k;
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};
