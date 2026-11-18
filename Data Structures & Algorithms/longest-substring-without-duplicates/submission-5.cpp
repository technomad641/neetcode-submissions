class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int r = s.length();
        //if(r==0) return 0;
        if(r<2) return r;
        int ans = 0;
        map< char, int > m;
        for(int right=0;right<r;right++){
            m[s[right]]++;
            while(left<=right && m[s[right]]>1){
                m[s[left]]--;
                ++left;
            }
            ans = max(ans, right-left+1);

        }
        return ans;
    }
};
