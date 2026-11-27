class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        int sz = nums.size();
        int max_ans = 0;
        for(int i=0;i<sz;i++){
            if(nums[i]==1 && nums[i]!= prev){
                ans = 1;
                prev = 1;
            }else{
                if(nums[i]==prev && prev == 1)++ ans;
                else prev = 0;
            }
            max_ans = max(ans, max_ans);
        }
        return max_ans;

    }
};