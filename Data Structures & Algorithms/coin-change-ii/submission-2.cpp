class Solution {
public:
    unordered_map< int, unordered_map<int, int> >dp;
    int recur(int amount, int index, vector<int>& coins){
        if(amount ==0) return 1;
        if(amount< 0 || index>=coins.size()) return 0;
        if(dp.find(amount)!= dp.end() && dp[amount].find(index)!= dp[amount].end()) return dp[amount][index];
        int taken = recur(amount- coins[index], index, coins);
        int left = recur(amount, index+1, coins);
        return dp[amount][index]= left+ taken;
    }
    int change(int amount, vector<int>& coins) {
        int ans = recur(amount, 0, coins);
        return ans == 0 ? 0: ans;
    }
};
