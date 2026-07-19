class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int maxJ = 0;
        for(int i=0;i<sz;i++){
            if(maxJ<i) return false;
            maxJ = max(maxJ, i+ nums[i]);
        }
        return true;
    }
};
