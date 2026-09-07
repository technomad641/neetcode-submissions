class Solution {
public:
    vector<int> vis;

    bool dfs(int index, vector<int>& nums, int& sz,
             int s, int& req, int countedK, int k) {

        // We have successfully created k subsets
        if(countedK == k)
            return true;

        // Current subset is complete.
        // Start building the next subset.
        if(s == req) {
            return dfs(0, nums, sz, 0, req, countedK + 1, k);
        }

        if(index >= sz)
            return false;

        for(int i = index; i < sz; i++) {

            if(vis[i] == 1)
                continue;

            if(s + nums[i] > req)
                continue;

            vis[i] = 1;

            if(dfs(i + 1, nums, sz,
                   s + nums[i], req, countedK, k))
                return true;

            vis[i] = 0;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sz = nums.size();

        vis.resize(sz, 0);

        int total = 0;

        for(auto x : nums)
            total += x;

        if(total % k != 0)
            return false;

        int req = total / k;

        return dfs(0, nums, sz, 0, req, 0, k);
    }
};