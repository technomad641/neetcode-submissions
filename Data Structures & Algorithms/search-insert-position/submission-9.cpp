class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h = nums.size()-1;
        int ans = nums.size();
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]>=target){
                ans = m;
                --h;
            }else ++l;
        }
        return ans;
    }
};