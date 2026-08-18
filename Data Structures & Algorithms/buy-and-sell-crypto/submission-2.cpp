class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz<2) return 0;
        int profit = 0;
        int mm = prices[0];
        for(int right = 1;right< sz;right++){
            mm = min(mm, prices[right]);
            profit = max(profit, prices[right]-mm);
        }
        return profit;
    }
};
