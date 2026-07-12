class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        if(sz ==1) return nums[sz-1];
        else ans = nums[0];
        //int i=0;
        //vector< int > pre(sz+1, 0);
        int S = 0;
        for(int i=0; i< sz;i ++){
            if(i==0) S= nums[i];
            else{
               S = max(nums[i], S+ nums[i]);
                
            }
            ans = max(ans, S);
            //i++;
        }
        return ans;
    }
};
