class Solution {
public:
    struct Node{
        map< char, struct Node*> nei;
        map< char, int > cnt;
        bool isend;
    };
    struct Node* root;
    void insert(string word){
        struct Node* t = root;
        for(char x: word){
            //cout<< x<<" ";
            if(t->nei.find(x)!= t->nei.end()){
                t->cnt[x]++;
                t = t->nei[x];
                
            }else{
                 struct Node* p = new struct Node();
                 t->cnt[x]++;
                 t->nei[x] = p;
                 //p->cnt[x]++;
                 //cout<< x<<" "<< p->cnt[x];
                 t = p;
            }
        }
        //t->isend = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        root = new  struct Node();
        int sz = strs.size();
        string ans = "";
        if(sz == 0) return "";
        if(sz == 1) return strs[0];
        for(auto x: strs){
            insert(x);
        }
        struct Node* t = root;
        while(t){
            bool found = false;
            for(char x = 'a'; x<='z'; x++){
                if(t->cnt[x] == sz){
                    ans = ans+x;
                    t = t->nei[x];
                    found = true; break;
                }
            }
            if(!found)
            break;
        }
        return ans;
    }
};