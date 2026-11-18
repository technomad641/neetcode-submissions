class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        int pos = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target){
                pos = m;
                break;
            }
            if(target>nums[m]){
                l =m+1;
                pos =l;
            }else{
                r = m-1;
                pos = m;
            }
        }
        return pos;
    }
};