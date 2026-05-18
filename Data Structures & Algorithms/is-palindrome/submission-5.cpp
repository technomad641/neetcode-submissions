class Solution {
public:
    bool isNum( char x){
        return x>='0' && x<='9';
    }

    bool isAlphaNum( char x){
        return x>='A' && x<='Z' || x>='a' && x<='z' || x>='0' && x<='9' ;
    }
    char upperToLower(char x){
        return x-'A'+'a';
    } 
    bool isPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            while(s[i]==' ') {
                i++;
            }
            while(i<=j && s[j]==' '){
                j--;
            }

            while(i<=j &&!isAlphaNum(s[i])){
                i++;
            }
            while(i<=j &&!isAlphaNum(s[j])){
                j--;
            }

            if(i<=j && isNum(s[i])){
                if(!isNum(s[j])) return 0;
                if(s[i]!=s[j]) return 0;
            }else{
                if(i<=j &&s[i]>='A' && s[i]<='Z'){
                    s[i] = upperToLower(s[i]);
                }
                if(i<=j &&s[j]>='A' && s[j]<='Z'){
                    s[j] = upperToLower(s[j]);
                }
                if(i<=j &&s[i]!=s[j]) return 0;
                
            }
            i++;
            --j;
        }
        return 1;
    }
};
