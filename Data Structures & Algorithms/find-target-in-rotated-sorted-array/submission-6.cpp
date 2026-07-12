class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(right  ==0){
            if(nums[right]==target) return right;
            else return -1;
        }
        
        while(left<right){
            int m = left+(right -left)/2;
            if(nums[m]==target) return m;
            if(nums[m]>=nums[left]){
                if(target >=nums[left] && target<=nums[m]) right = m-1;
                else left = m+1;
            }else{
                if(target >=nums[m] && target<=nums[right]) left = m+1;
                else right = m-1;
            }
        }
        if(nums[left]==target) return left;
        return -1;
    }
};
