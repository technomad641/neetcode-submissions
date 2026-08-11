class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        vector< int> prefix(sz, 1);
        vector< int> suffix(sz, 1);
        bool isneg = false;
        bool iszero= false;
        bool ispos = false;
        if(sz==1) return nums[sz-1];
        int ans = nums[0];
        for(int i=0;i<sz;i++){
            if(nums[i]==0){
                prefix[i]=1;
                suffix[sz-i-1]=1;
               // ans = max(ans, nums[i]); continue;
            }else if(i==0){
                prefix[i]= nums[i];
                suffix[sz-i-1] = nums[sz-i-1];
            }else{
                prefix[i] = nums[i]*prefix[i-1];
                suffix[sz-i-1]=nums[sz-i-1]*suffix[sz-i];
            }
            if(nums[i]==0) iszero = true;
            if(nums[i]<0) isneg = true;
            if(nums[i]>0) ispos = true;
            ans = max(ans, nums[i]);
            ans = max(ans, prefix[i]);
            ans = max(ans, suffix[sz-i-1]);
        }
        if(ispos==false && isneg && iszero) return 0;
        return ans;
    }
};
