class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        int st = nums[0];
        int ans = st;
        vector< int > pre(sz, 0);
        for(int i=0;i<sz;i++){
            if(i ==0){
                pre[i] = nums[i];
            }else{
                if(nums[i]==0){
                    ans = max(ans, nums[i]);
                    pre[i]=1;
                }
                else {
                    pre[i] = nums[i]*pre[i-1];
                    ans = max(ans, pre[i]);
                }
            }
        }
        pre.clear();
        for(int i=sz-1;i>=0;i--){
            if(i ==sz-1){
                pre[i] = nums[i];
                ans = max(ans, nums[i]);
            }else{
                if(nums[i]==0){
                    ans = max(ans, nums[i]);
                    pre[i]=1;
                }
                else {
                    pre[i] = nums[i]*pre[i+1];
                    ans = max(ans, pre[i]);
                }
            }
        }
        return ans;
    }
};
