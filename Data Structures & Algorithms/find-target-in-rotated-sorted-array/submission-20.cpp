class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        if(r-l+1 == 1){
            return target == nums[l] ? 0: -1;
        }
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]== target) return m;
            if(nums[m]> nums[r]){
                // left is sorted and right is unsorted
                //left -> [l, m]
                if(target>=nums[l] && target<nums[m]){
                    r = m-1;
                }else  l= m+1;
            }else{
                // right is sorted and left is unsorted
                // [m]
                if(target>nums[m] && target<=nums[r]){
                    l = m+1;
                }else  r= m-1;
            }
        }
        return -1;
    }
};
