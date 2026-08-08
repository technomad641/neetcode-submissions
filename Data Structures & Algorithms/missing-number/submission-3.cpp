class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int S =0;
        int sz = nums.size();
        for(int i=0;i<=sz;i++){
            S^=i;
            if(i<sz)S^=nums[i];
        }
        
        return S;
    }
};
