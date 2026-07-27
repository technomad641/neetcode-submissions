class Solution {
public:
    map< int , int > dp;
    int recur(vector<int>& cost, int index){
        if(index>=cost.size()) return dp[index] = 0;
        if(dp.find(index)!=dp.end()) return dp[index];
         return dp[index] = cost[index] + min(recur(cost, index+1), recur(cost, index+2));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        if(sz == 1) return cost[0];
        return min(recur(cost, 0) , recur(cost, 1));
    }
};
