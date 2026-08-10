class Solution {
public:
    unordered_map< int, unordered_map< int , int > >dp;
    int dfs(int amount, vector<int>& coins, int index){
        if(index == coins.size()){
            if(amount ==0){
                return dp[amount][index] = 0;
            }
            return dp[amount][index] = -1;
        }
        if(amount == 0) return dp[amount][index] = 0;
        if(amount <0) return dp[amount][index] = -1;
       int mintaken = -1;
       if(amount>=coins[index]){
            mintaken = dfs(amount-coins[index], coins, index);
            if(mintaken != -1) ++mintaken;
       }
       if(dp.find(amount)!= dp.end() && dp[amount].find(index)!= dp[amount].end()) return dp[amount][index];
       // int 
        int skipped = dfs(amount, coins, index+1);
        if(skipped == -1 && mintaken == -1) return dp[amount][index]=-1;
        if(skipped == -1) return dp[amount][index] = mintaken;
        if(mintaken == -1) return dp[amount][index] = skipped;
        return dp[amount][index]= min(skipped, mintaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        return dfs(amount , coins, 0);
        
    }
};
