class Solution {
public:
    bool isValid(string s) {
        stack< char > st;
        for(auto x: s){
            if(st.empty()) st.push(x);
            else{
                while(!st.empty()){
                 char p = st.top();
                    if(p=='[' && x==']' || p=='{' && x=='}' || p=='(' && x== ')') {
                        st.pop();
                        break;
                        }
                    else {st.push(x); break;}
                }
            }
        }
        return st.empty();
    }
};
