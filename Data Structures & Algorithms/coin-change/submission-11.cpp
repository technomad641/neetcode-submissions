class Solution {
public:
    unordered_map< int, unordered_map<int, int> >dp;
    int recur(int amount, int index, vector<int>& coins){
        if(amount ==0) return 0;
        if(amount< 0 || index>=coins.size()) return 10001;
        if(dp.find(amount)!= dp.end() && dp[amount].find(index)!= dp[amount].end()) return dp[amount][index];
        int taken = 1+ recur(amount- coins[index], index, coins);
        int left = recur(amount, index+1, coins);
        return dp[amount][index]=min(taken, left);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = recur(amount, 0, coins);
        return ans == 10001 ? -1: ans;
    }
};
