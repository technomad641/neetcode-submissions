class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int ans =0;
        for(int u=1;u<sz;u++){
            if(prices[u]>prices[u-1]) ans+=(prices[u]-prices[u-1]);
        }
        return ans;
    }
};