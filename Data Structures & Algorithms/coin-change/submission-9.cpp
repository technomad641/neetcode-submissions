class Solution {
public:
unordered_map< int, unordered_map<int, int> > dp;
    int recur(int index, int amount,  vector<int>& coins){
        if(index == coins.size()){
             return dp[index][amount]= (amount ==0 ? 1 : INT_MAX);
        }
        if(amount <= 0) {
            return dp[index][amount]= amount ==0 ? 1 : INT_MAX;
        }
        if(dp.find(index)!=dp.end() && dp[index].find(amount)!= dp[index].end()) return dp[index][amount];
        int take =  recur(index, amount-coins[index], coins);   
        if(take != INT_MAX) take+=1;         
        int leave = recur(index+1, amount, coins);
        //if(leave != INT_MAX) leave =0;  

        return  dp[index][amount]=min(take, leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = recur(0, amount, coins);
        return ans == INT_MAX ? -1 : ans-1;
    }
};
