class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int start = nums[0];
        int cnt = 1;
        for(int i=1;i<sz;i++){
            if(start == nums[i]){
                ++cnt;
            }else{
                --cnt;
            }
            if(cnt ==0) {
                start = nums[i];
                ++cnt;
            }
            if(cnt>=(sz/2)) return start;
        }
        return start;
    }
};