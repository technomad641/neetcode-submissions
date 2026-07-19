class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< vector< int> , vector< string > >mp;
        for(auto x: strs){
            vector< int > cnt(26, 0);
            for(auto z: x){
                cnt[z-'a']++;
            }
            mp[cnt].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        } 
        return ans;
    }
};
