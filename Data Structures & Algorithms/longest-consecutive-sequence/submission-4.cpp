class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        unordered_map< int, int > cnt;
        int ans = 0;
        int len =0;
        //cout<<sz<<endl;
        for(int i=0;i<sz;i++){
            int val = nums[i];
            if(cnt.find(val)!=cnt.end()) continue;
            
            len = 1+ (((cnt.find(val-1) != cnt.end())?cnt[val-1]:0) +
            ((cnt.find(val+1) != cnt.end())?cnt[val+1]:0));
            cnt[val]= len;
            cnt[val-((cnt.find(val-1)!= cnt.end())?cnt[val-1]:0)]= len;
            cnt[val+((cnt.find(val+1)!= cnt.end())?cnt[val+1]:0)]= len;
            ans = max(ans, len);
            //cout<< len<<endl;
        }
        return ans;
    }
};
