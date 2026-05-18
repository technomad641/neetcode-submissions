class Solution {
public:
    int characterReplacement(string s, int k) {
        int sz = s.length();
        int  l = 0;
        int ans =0;
        map< char, int > charSet;
        int maxFreq = 0;
        for(int r =0;r< sz;r++){
            charSet[s[r]]++;
            maxFreq = max(maxFreq, charSet[s[r]]);
            while((r - l + 1) - maxFreq > k && l<=r){
                    charSet[s[l]]--;
                    l++;
                    maxFreq = 0;
                    for(auto const& [key, val] : charSet) maxFreq = max(maxFreq, val);
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};