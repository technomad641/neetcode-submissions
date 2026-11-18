class Solution {
public:
    vector<string> result;
    void recur(int open, int close, string temp, int N){
        if(open==N && close ==N){
            result.push_back(temp);
            return;
        }
        if(open < N){
            temp = temp + "(";
            recur(open+1, close, temp, N);
            temp.pop_back();
        }
        if(close< open){
            temp = temp + ")";
            recur(open, close+1, temp, N);
            temp.pop_back();

        }
        
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        recur(0, 0, temp, n);
        return result;
    }
};
