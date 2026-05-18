class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map< int, int > cnt;
        for(auto x: nums){
            cnt[x]++;
            if(cnt[x]>1) return true;
        }
        return false;
    }
};