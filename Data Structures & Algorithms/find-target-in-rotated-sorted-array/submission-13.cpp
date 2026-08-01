class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi =nums.size()-1;
        int ans = -1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(nums[m]==target) return m;
            if(nums[hi]>nums[m]){
                    if(target>=nums[m]&& target<=nums[hi]) lo = m+1;
                    else hi = m-1;
                }else{
                    if(target>=nums[lo]&& target<=nums[m]) hi = m-1;
                    else lo = m+1;
                }
        }
        return ans;
    }
};
