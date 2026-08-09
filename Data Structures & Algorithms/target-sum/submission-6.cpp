class Solution {
public:
    unordered_map<int, unordered_map<int, int > > dp;
    int dfs(int S, int target,vector<int>& nums, int index){
        if(index == nums.size()){ //last index also done
            if(S== target) return dp[S][index]=1;
            else return dp[S][index]=0;
        }
        if(dp.find(S)!= dp.end() && dp[S].find(index)!= dp[S].end()){
            cout<<dp[S][index]<<endl;
             return dp[S][index];
        }
        int takeminus = dfs(nums[index]+ S, target, nums, index+1);
        int takeplus = dfs(-nums[index]+ S,target, nums, index+1);
       // cout<<takeplus<<" "<<takeminus<<endl;
        return dp[S][index]= takeplus + takeminus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0,target, nums, 0);
    }
};
