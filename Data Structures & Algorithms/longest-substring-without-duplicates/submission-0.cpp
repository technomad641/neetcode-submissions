class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int sz = s.length();
        int l =0;
        int ans = 0;
        map< char, int > cnt;
        for (int r =0;r < sz; r++){
            cnt[s[r]]++;
            while(cnt[s[r]]>1 && l<=r){
                cnt[s[l]]--;
                ++l;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
