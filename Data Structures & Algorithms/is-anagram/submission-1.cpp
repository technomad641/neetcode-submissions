class Solution {
public:
    bool isAnagram(string s, string t) {
        map< int, int> cnt;
        int LN=0;
        for(char x: s){
            cnt[x-'a']++;
            if(cnt[x-'a']==1) LN++;
        }
        for(auto x: t){
            if(cnt.find(x-'a')!= cnt.end()){
                cnt[x-'a']--; 
                if(cnt[x-'a']==0) LN--; 
            }else LN++; 
        }
        return LN==0;
    }
};
