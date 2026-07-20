class Solution {
public:
    map<int, int> dp;

    bool dfs(int start, vector<int>& nums) {
        if (dp.find(start) != dp.end())
            return dp[start];

        if (start >= nums.size() - 1)
            return dp[start] = true;

        if (nums[start] == 0)
            return dp[start] = false;

        int en = min(start + nums[start], (int)nums.size() - 1);

        for (int i = start + 1; i <= en; i++) {
            if (dfs(i, nums))
                return dp[start] = true;
        }

        return dp[start] = false;
    }

    bool canJump(vector<int>& nums) {
        return dfs(0, nums);
    }
};