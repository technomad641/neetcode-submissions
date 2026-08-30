class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;

        // remainder 0 before processing anything
        m[0] = 0;

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if (m.find(rem) != m.end()) {
                // Need at least 2 elements
                if (i + 1 - m[rem] >= 2)
                    return true;
            }
            else {
                // Store ONLY the first occurrence
                m[rem] = i + 1;
            }
        }

        return false;
    }
};