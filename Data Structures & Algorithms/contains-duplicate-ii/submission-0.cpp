class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int sz = nums.size();
        int l =0;
        map< int, int> cnt;
        for(int r =0;r<sz;r++){
            if(cnt.find(nums[r])!=cnt.end()){
                if(abs(r - cnt[nums[r]])<=k) return 1;
            }
            cnt[nums[r]] = r;
        }
        return 0;
    }
};