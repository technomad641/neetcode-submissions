class Solution {
public:
    // first element >=target 
    // [2,3,5,6,7,12,34]
    int searchInsert(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        int pos = r+2;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target){
                pos = m;
                break;
            }
            if(target>nums[m]){// target is bigger than mid hence
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