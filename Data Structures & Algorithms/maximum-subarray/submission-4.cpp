class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sz = nums.size();
        int ans = nums[0];
        int s = nums[0];
        int localSum = s;
        for(int i=1;i<sz;i++){
            localSum+=nums[i];
            if(localSum< nums[i]){
                localSum = nums[i];
            }
            ans = max(ans,localSum);
        }
        return ans;
    }
};
