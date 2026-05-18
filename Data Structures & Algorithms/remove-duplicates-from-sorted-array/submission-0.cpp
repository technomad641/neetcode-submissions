class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz ==0) return sz;
        int j=0;
        for(int i=1;i<sz;i++){
            if(nums[j]!=nums[i]){
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};