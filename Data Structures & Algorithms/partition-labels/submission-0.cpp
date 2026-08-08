class Solution {
public:
    map< char, int > m;
    int cnt =0;
    vector< int > ans;
    void dfs(string s, int index, int sz){
        if(index==sz) return;
        int endindex = index;
        for(int i=index;i<sz;i++){
            endindex = max(endindex, m[s[i]]);
            if( i== endindex){
                ans.push_back(endindex-index+1);
                dfs(s, i+1, sz);
                break;
            }
        }
    }
    vector<int> partitionLabels(string s) {
        int sz = s.length();
        ans.clear();
        for(int i=0;i<sz;i++){
            m[s[i]] = i;
        }
        dfs(s, 0, sz);
        return ans;

    }
};
