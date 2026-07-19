class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string , vector< string > >mp;
        for(auto x: strs){
            vector< int > cnt(26, 0);
            for(auto z: x){
                cnt[z-'a']++;
            }
            string K = "";
            for(int i=0;i<26;i++){
                K+=to_string(cnt[i]) + ',' + to_string(i);
            }
            mp[K].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        } 
        return ans;
    }
};
