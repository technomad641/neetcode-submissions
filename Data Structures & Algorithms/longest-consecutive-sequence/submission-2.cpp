class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(begin(nums), end(nums));
        int ans = 0;
        //map< int, int >
        for(auto x: st){
            if(st.find(x-1)==st.end()){
                int L = 1;
                while(st.find(x+L)!=st.end()) ++L;
                ans = max(ans, L);
            }

        }
        return ans;
    }
};
 