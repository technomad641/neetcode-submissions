class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map< char, int > m;
        unordered_map< char, int > cnt;
        for(char x: t) m[x]++;
        int left = 0;
        int sz = s.length();
        int st = -1;
        int minLen = INT_MAX;
        int p = m.size();
        int len = 0;
        for(int right = 0;right<sz;right++){
            if(m.find(s[right])== m.end()) continue;
            cnt[s[right]]++;
            if(cnt[s[right]] == m[s[right]]) ++len;
            while(left<=right && len == p){
                if(m.find(s[left])== m.end()) {
                    ++left; 
                    continue;
                }
                if(minLen >right-left+1){
                    st = left;
                    minLen = right-left+1;
                }
                cnt[s[left]]--;
                if(cnt[s[left]]< m[s[left]]) --len;
                ++left;
               
            }
        }
        return minLen==INT_MAX ? "": s.substr(st, minLen);
    }
};
