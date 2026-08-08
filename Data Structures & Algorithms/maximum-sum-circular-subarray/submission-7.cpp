class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1) return nums[0];
        if(sz==0) return 0;
        int maxSum =nums[0];
        int minSum =nums[0];
        int curSum =nums[0];
        int curMin =nums[0];
        int total =nums[0];
        for(int i=1;i<sz;i++){
            total+=nums[i];
            curSum = max(curSum+nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
            curMin = min(curMin+ nums[i], nums[i]);
            minSum = min(minSum, curMin);
        }
        if(maxSum< 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};