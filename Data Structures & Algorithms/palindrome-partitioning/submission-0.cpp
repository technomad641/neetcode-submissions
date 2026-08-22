class Solution {
public:
    vector<vector<string>>ans;
    bool isPalin(string s){
       int sz = s.length();
       int l=0;
       int r = sz-1;
       while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
       }
       return true;
    }
    void recur(string s, vector<string>&temp, int index){
        if(index== s.length()){
            ans.push_back(temp);
            return;
        }
        int sz = s.length();
        for(int i=1;i<=sz-index;i++){
            string newS = s.substr(index, i);
            if(isPalin(newS)){
                temp.push_back(newS);
                recur(s, temp, index+i);
                //ans.push_back(temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        recur(s, temp, 0);
        return ans;
    }
};

