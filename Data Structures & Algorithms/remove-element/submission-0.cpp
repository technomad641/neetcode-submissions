class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int j= 0;
        for(int i=0;i<sz;i++){
            if(nums[i]!= val){
                nums[j++]= nums[i];
            }
        }
        return j;
    }
};