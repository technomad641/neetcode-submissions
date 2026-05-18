class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int minPrice = INT_MAX;
        for(auto x: prices){
            minPrice = min(minPrice, x);
            ans = max(ans, x - minPrice);
        }
        return ans;
    }
};
