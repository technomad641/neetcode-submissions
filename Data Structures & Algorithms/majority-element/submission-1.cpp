class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int cnt =0;
        int ans = -1;
        for(auto x: nums){
            if(cnt == 0){
                ++cnt;
                ans = x;
            }else if(ans == x){
                ++cnt;
                if(cnt > sz/2) return ans;
            }else{
                --cnt;
            }
        }
        return ans;
    }
};