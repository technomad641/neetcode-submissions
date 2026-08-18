class Solution {
public:
    int characterReplacement(string s, int k) {
        int sz = s.length();
        int maxlen = 0;
        int left =0;
        unordered_map< char, int > count;
        int max_freq = 0;
        for(int right =0;right< sz;right++){
            count[s[right]]++;
            max_freq = max(max_freq,count[s[right]] );
            while(left<=right && max_freq+k <(right-left+1)){
                --count[s[left]];
                 max_freq = max(max_freq,count[s[left]] );
                if(count[s[left]]==0)  count.erase(s[left]);
                ++left;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};

// commmon + distinct < k
//L........R
