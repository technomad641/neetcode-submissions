class Solution {
public:
    bool isValid(string s) {
        stack< char > st;
        int sz = s.length();
        for(int r =0;r<sz;r++){
            if(st.empty()) st.push(s[r]);
            else{
                if(s[r]=='{' || s[r]=='[' || s[r]=='(') st.push(s[r]);
                else{
                   // while(!st.empty()){
                        if(!st.empty() && st.top()=='[' && s[r]==']')
                        st.pop();
                        else if(!st.empty() && st.top()=='{' && s[r]=='}')
                        st.pop();
                        else if(!st.empty() && st.top()=='(' && s[r]==')')
                        st.pop();
                       else break;

                   // }
                }
            }
        }
        return st.empty();
    }
};
