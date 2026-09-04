class Solution {
public:
    vector< int>dp;
    int minJumps(int index, vector<int>& nums){
        if(index ==0) return dp[index]=0;
        int ans = INT_MAX;
        if(dp[index]!= -1) return dp[index];
        for(int prev = index-1;prev>=0;prev--){
            if(index-prev <= nums[prev]){
                ans = min(ans, 1+minJumps(prev, nums));
            }
        }
        return dp[index]=ans;
    }
    int jump(vector<int>& nums) {
       
        int sz = nums.size();
        dp = vector<int>(sz+1, -1);
        return minJumps(sz-1, nums);
    }
};
