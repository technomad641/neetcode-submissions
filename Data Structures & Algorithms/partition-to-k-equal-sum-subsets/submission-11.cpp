class Solution {
public:
    vector<int> vis;

    bool dfs(int index, vector<int>& nums, int sz,
             int sum, int req, int groupsLeft) {

        // We successfully created k groups
        if(groupsLeft == 0)
            return true;

        // Current group completed
        if(sum == req) {
            return dfs(0, nums, sz, 0, req, groupsLeft - 1);
        }

        for(int i = index; i < sz; i++) {

            if(vis[i])
                continue;

            if(sum + nums[i] > req)
                continue;

            vis[i] = 1;

            if(dfs(i + 1, nums, sz,
                   sum + nums[i], req, groupsLeft))
                return true;

            vis[i] = 0;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sz = nums.size();

        int total = 0;

        for(int x : nums)
            total += x;

        if(total % k != 0)
            return false;

        int req = total / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > req)
            return false;

        vis.resize(sz, 0);

        return dfs(0, nums, sz, 0, req, k);
    }
};