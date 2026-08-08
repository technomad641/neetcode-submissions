class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int S =0;
        int sz = nums.size();
        for(int i=0;i<=sz;i++){
            S^=i;
        }
        for(int i=0;i<sz;i++){
            S^=nums[i];
        }
        return S;
    }
};
