class Solution {
public:
    unordered_map< int, unordered_map< int , int > >dp;
    int dfs(int amount, vector<int>& coins, int index){
        //Base Conditions
        if(index == coins.size()){
            if(amount ==0){
                return dp[amount][index] = 0; // valid
            }
            return dp[amount][index] = -1; // invalid state
        }
        if(amount == 0) return dp[amount][index] = 0; // valid state
        if(amount < 0) return dp[amount][index] = -1; // invalid state

       int mintaken = -1;
       if(amount>=coins[index]){ // we take this coin and move on
            mintaken = dfs(amount-coins[index], coins, index);
            if(mintaken != -1) mintaken++; // only increment if its valid
       }
       if(dp.find(amount)!= dp.end() && dp[amount].find(index)!= dp[amount].end()) return dp[amount][index]; // already found so return it
       // int 
        int skipped = dfs(amount, coins, index+1); // skipped case
        if(skipped == -1 && mintaken == -1) return dp[amount][index]=-1;
        if(skipped == -1) return dp[amount][index] = mintaken;
        if(mintaken == -1) return dp[amount][index] = skipped;
        return dp[amount][index]= min(skipped, mintaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        return dfs(amount , coins, 0);
        
    }
};
