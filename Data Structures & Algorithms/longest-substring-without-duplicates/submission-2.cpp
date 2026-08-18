class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.length();
        int maxlen = 0;
        int left = 0;
        unordered_set< char > count;
        for(int right = 0;right<sz;right++){
            while(left<=right && !count.empty() && count.find(s[right])!= count.end()){
                count.erase(s[left]);
                ++left;
            }
            count.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
