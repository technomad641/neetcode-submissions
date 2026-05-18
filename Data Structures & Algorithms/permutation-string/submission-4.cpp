class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz = s1.length();
        int sz2 = s2.length();
        int l = 0;
        map< char, int > cnt;
        map< char, int > CNTS1;
        for(auto x: s1){
            CNTS1[x]++;
        }
        for(int r =0;r< sz2;r++){
            cnt[s2[r]]++;
            if(r-l+1 >sz && l<=r){
                cnt[s2[l]]--;
                if (cnt[s2[l]] <= 0) cnt.erase(s2[l]);
                ++l;
                
            }
            if(CNTS1 == cnt) return 1;
        }
        if(CNTS1 == cnt) return 1;
        return 0;
    }
};
