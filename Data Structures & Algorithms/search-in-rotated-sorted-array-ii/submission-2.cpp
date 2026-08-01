class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;

            if (nums[m] == target)
                return true;

            // Can't determine sorted half because of duplicates
            if (nums[lo] == nums[m] && nums[m] == nums[hi]) {
                lo++;
                hi--;
            }
            // Left half is sorted
            else if (nums[lo] <= nums[m]) {
                if (nums[lo] <= target && target < nums[m])
                    hi = m - 1;
                else
                    lo = m + 1;
            }
            // Right half is sorted
            else {
                if (nums[m] < target && target <= nums[hi])
                    lo = m + 1;
                else
                    hi = m - 1;
            }
        }

        return false;
    }
};