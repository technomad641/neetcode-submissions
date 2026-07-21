class Solution {
public:
vector<vector<int>> ans;
    void dfs(vector<int>& nums, int target, int S, int i, vector<int>T){
        if(target ==0){
            ans.push_back(T);
            return;
        }
        if(target<0) return;
        int sz = nums.size();
        for(int j=i;j<sz;j++){
            T.push_back(nums[j]);
            dfs(nums, target-nums[j], S, j, T);
            T.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector< int > T;
        dfs(nums, target, 0, 0, T);
        return ans;
    }
};
