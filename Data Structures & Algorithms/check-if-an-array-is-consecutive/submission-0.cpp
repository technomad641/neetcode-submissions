class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int sz = nums.size();
        int prev = nums[0];
        for(int i=1;i<sz;i++){
            if(nums[i]!= prev+1) return false;
            prev = nums[i];
        }
        return true;
    }
};
