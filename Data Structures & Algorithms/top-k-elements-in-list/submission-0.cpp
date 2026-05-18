class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map< int, int> cnt;
        vector< int > ans;
        priority_queue< vector<int> , vector<vector<int>>> PQ;
        for(auto x: nums) cnt[x]++;
        for(auto x: cnt){
            PQ.push({ x.second, x.first});
        }
        while(k>0 && !PQ.empty()){
            vector< int> A = PQ.top(); PQ.pop();
            ans.push_back(A[1]);
            --k;
        }
        return ans;
    }
};
