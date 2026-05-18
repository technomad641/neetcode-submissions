class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int sz = s.length();
        int r =0;
        int ans =0;
        map< char, int > cnt;
        for(int i=0;i<sz;i++){
            cnt[s[i]]++;
            while(cnt[s[i]]>1 && l<i){
                cnt[s[l++]]--;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
