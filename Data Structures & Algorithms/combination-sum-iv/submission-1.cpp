
class Solution {
public:
    unordered_map<int, int> memo;

    int recur(int amount, vector<int>& nums) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;
        if (memo.count(amount)) return memo[amount];

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += recur(amount - nums[i], nums);
        }
        return memo[amount] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return recur(target, nums);
    }
};

