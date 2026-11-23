class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int sz = nums.size();
        if(sz == 0) return 0;
        int ans = 1;
        int max_ans = 1;
        int prev = nums[0];
        for(int i=1;i<sz;i++){
            if(nums[i]==prev) continue;
            if(nums[i]==prev+1){
                ++ans;
                prev = nums[i];
            }else{
                prev = nums[i];
                ans = 1;
            }
            max_ans = max(ans, max_ans);
        }
        return max_ans;
    }
};
