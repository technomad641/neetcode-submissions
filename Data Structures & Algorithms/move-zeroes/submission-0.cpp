class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int k=0;
        for(int i=0;i<sz;i++){
            if(nums[i]!=0) nums[k++] = nums[i];
        }
        while(k<sz){
            nums[k]=0;
            ++k;
        }
    }
};