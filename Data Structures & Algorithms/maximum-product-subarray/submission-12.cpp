class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sz = nums.size();
        int ans = nums[0];
        int s = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];
        int minProdNew = nums[0];
        int maxProdNew = nums[0];
        for(int i=1;i<sz;i++){
            maxProd = max(nums[i], nums[i]*maxProdNew);
            maxProd = max(maxProd, nums[i]*minProdNew);

            minProd = min(nums[i], nums[i]*minProdNew);
            minProd = min(minProd, nums[i]*maxProdNew);
            
            minProdNew = minProd;
            maxProdNew = maxProd;
            
            ans = max(ans, maxProdNew);
        }
        return ans;
        
    }
};
