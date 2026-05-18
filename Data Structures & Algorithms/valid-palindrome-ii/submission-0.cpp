class Solution {
public:
  bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return 0;
        ++i;
        --j;
    }
    return 1;
  }
    bool validPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                ++i;
                --j;
            }else{
                return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
            }
        }
        return 1;
    }
};