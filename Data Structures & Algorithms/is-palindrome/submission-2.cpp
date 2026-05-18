class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(!isIgnore((s[start]))){++start; continue;}
            else if(!isIgnore((s[end]))){--end;continue;}
            else if(tolower(s[start]) != tolower(s[end])) return false;
            ++start;
            --end;
        }
        return true;  
    }

    bool isIgnore(char x){
        if((x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9')) return 1;
        return 0;
    }
};
