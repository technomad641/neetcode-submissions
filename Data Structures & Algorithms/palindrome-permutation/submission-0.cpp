class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map< char, int > cnt;
        for(auto x: s) cnt[x]++;
        int odd = 0;
        int even = 0;
        for(auto x: cnt){
            if(x.second%2==1) ++odd;
            else ++even;
        }
        return odd == 1 || odd ==0;
    }
};
