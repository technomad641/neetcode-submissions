class Solution {
public:
    unordered_map< string , int > m;
    unordered_map< int , int > dp;
    int len =0;
    bool dfs(int index, string s){
        if(index == len) return dp[index] = true;
        int sz = s.length();
        if(dp.find(index)!= dp.end()) return dp[index];
        for(int i=1;i<=sz;i++){
            string temp = s.substr(index, i);
            if(m.find(temp) != m.end() && dfs(index+i,s)) return true;
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict) m[x]++;
        len = s.length();
        return dfs(0,s);
    }
};
