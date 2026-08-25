class Solution {
public:
    map< int, map<int, int >>dp;
    bool recur(int index, vector<int>& nums, int target){
        if(index == nums.size()) return  dp[index][target] = target ==0;
        if(target<=0) return  dp[index][target] = target ==0;
        if(dp.find(index)!= dp.end() && dp[index].find(target)!= dp[index].end()) return dp[index][target];
        // take the number
        bool take = recur(index+1, nums, target-nums[index]);
        // ignore
        bool ignore = recur(index+1, nums, target);
        return dp[index][target]=take || ignore;
    }
    bool canPartition(vector<int>& nums) {
        int s =0;
        for( auto x: nums) s+=x;
        if(s%2==1) return 0;
        //s/=2;
        int target = s/2;
        return recur(0, nums, target);
    }
};
