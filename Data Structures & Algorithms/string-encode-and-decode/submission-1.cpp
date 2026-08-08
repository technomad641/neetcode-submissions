class Solution {
public:

    string encode(vector<string>& strs) {
        string delimiter = "<XXX>";
        string ans = "";
        for(auto str: strs){
            ans = ans + str + delimiter;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int sz = s.length();
        int st = 0;
        string temp ="";
        for(int i=0;i<sz;i++){
            temp = s[i]+ temp;
            if(temp.find(">XXX<") != -1){
                temp = temp.substr(5);
                reverse(begin(temp), end(temp));
                ans.push_back(temp);
                temp="";
            }
        }
        return ans;
    }
};
