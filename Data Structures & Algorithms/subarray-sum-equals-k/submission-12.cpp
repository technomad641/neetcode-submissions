class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map< int, int> cnt;
        cnt[0]=1;
        int pre = 0;
        int ans = 0;
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            pre+=nums[i];
            ans+= cnt[pre-k];
            cnt[pre]++;
        }
        return ans;
    }
};