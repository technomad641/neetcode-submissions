class Solution {
public:
    int findMin(vector<int> &nums) {
    int left = 0;
    int sz = nums.size()-1;
        int right = nums.size()-1;
        if(right  ==0){
            return nums[left];
        }
        
        while(left<right){
            int m = left+(right -left)/2;
            
            if(nums[m]>nums[sz]) left = m+1;
            else right = m;
        }
        return nums[left];
    }    
    
};
