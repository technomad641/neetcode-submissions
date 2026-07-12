class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        if(sz ==1) return nums[sz-1];
        else ans = nums[0];
        //int i=0;
        vector< int > pre(sz+1, 0);
        for(int i=0; i< sz;i ++){
            if(i==0) pre[i]= nums[i];
            else{
                pre[i] = max(nums[i], pre[i-1]+ nums[i]);
                
            }
            ans = max(ans, pre[i]);
            //i++;
        }
        return ans;
    }
};
