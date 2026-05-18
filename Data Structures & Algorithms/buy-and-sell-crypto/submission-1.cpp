class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int ans =0;
        int P = prices[0];
        for(int i=0;i<sz;i++){
            P= min(prices[i], P);
            ans = max(ans, prices[i]-P);
        }
        return ans;

    }
};
