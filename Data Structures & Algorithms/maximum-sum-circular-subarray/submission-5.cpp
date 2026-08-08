class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sz = nums.size();
        if(sz ==1) return nums[0];
        int S =nums[0];
        int Smin =nums[0];
        int ans = nums[0];
        int ansMin = nums[0];
        int t=nums[0];
        for(int i=1;i<sz;i++){
            t += nums[i];
            S = max(S+nums[i], nums[i]);
            ans = max(ans, S);
           Smin = min(Smin+nums[i], nums[i]);
           ansMin = min(Smin, ansMin);
        }
        if(ans<0) return ans;
        return max(ans, t-ansMin);
    }
};