class Solution {
public:
    bool valid(string s) {
    if (s[0] == '0') return false;

    if (s.length() == 2) {
        int num = stoi(s);
        return num >= 10 && num <= 26;
    }

    return true;
}
    unordered_map< string, unordered_map<int, int> >dp;
    int recur(string &s, int index){
        if(s == "") return 1;
        int ways = 0;
        int sz = s.length();
        if(dp.find(s)!= dp.end() && dp[s].find(index)!=dp[s].end()) return dp[s][index];
        if(sz-1>=0){
            string newS = s.substr(0,index);
            if(valid(s.substr(index, 1)))ways = recur(newS, index-1);
        }
        if(sz-2>=0){
            string newS2 = s.substr(0, index-1);
            if(valid(s.substr(index-1, 2))) ways += recur(newS2, index-2);
        }
        return dp[s][index]=ways;
    }
    int numDecodings(string s) {
        int sz = s.length();
        return recur(s, sz-1);
    }
};
