class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=1;
        int r = nums.size();
        while(l<r){
            if(nums[l-1]+ nums[r-1]==target){
                return {l, r};
            }else{
                if(nums[l-1]+ nums[r-1]>target){
                    r--;
                }else ++l;
            }
        }
        return {1, nums.size()};
    }
};
