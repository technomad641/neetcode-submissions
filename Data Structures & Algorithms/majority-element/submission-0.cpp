class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<sz;i++){
            if(cnt ==0){
                ans = nums[i];
                ++cnt;
            }else if(ans == nums[i]){
                ++cnt;
            }else{
                --cnt;
                if(cnt ==0) ans = nums[i];
            }
        }
        return ans;
    }
};