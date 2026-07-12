class Solution {
public:
    bool isValid(string s) {
        stack< char >st;
        for(auto x: s){
            if(x == ')' || x == '}' || x == ']'){
                if(st.empty()) return false;
                if(x == ')' && st.top()== '(') st.pop();
                else if(x == ']' && st.top()== '[') st.pop();
                else if(x == '}' && st.top()== '{') st.pop();
                else return false;
            }else st.push(x);
        }
        return st.empty();
    }
};
