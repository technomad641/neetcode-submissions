class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int > cnt;
        cnt[0]=1;
        int sz = nums.size();
        int ans =0;
        int pre =0;
        for(int i=0;i<sz;i++){
            pre+=nums[i];
            ans+=cnt[pre-k];
            cnt[pre]++;
        }
        return ans;
    }
};