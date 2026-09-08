
class Solution {
public:
    unordered_map<int, int> memo;

    int recur(int index, vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target< 0) return 0;
        if(memo.find(target)!=memo.end()) return memo[target];
        int sz = nums.size();
        int ans =0;
        for(int i=0;i<sz;i++){
            ans=ans+recur(index, nums, target-nums[i]);
        }
        return memo[target]=ans;
       
    }

    int combinationSum4(vector<int>& nums, int target) {
        return recur(0, nums, target);
    }
};

