class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int S =0;
        int p = nums.size();
        int L = p*(p+1);
        L/=2;
        for(auto x: nums) S+=x;
        return abs(S-L); 
    }
};
