class Solution {
public:
    unordered_map< int, unordered_map<int, int> > dp;
    int recur(int index, int amount,  vector<int>& coins){
        if(index == coins.size()) {
            return dp[index][amount] = (amount == 0);
        }
        if(amount <= 0) return dp[index][amount] = amount == 0;
        if(dp.find(index)!=dp.end() && dp[index].find(amount)!= dp[index].end()) return dp[index][amount];
        return  dp[index][amount] = recur(index, amount-coins[index], coins)  + recur(index+1, amount, coins);
    }
    int change(int amount, vector<int>& coins) {
        return recur(0, amount, coins);
    }
};
