class WordDictionary {
public:
    struct Node{
        char value;
        unordered_map< char, Node*> children;
        bool is_ends = false;
    };
    struct Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        int sz = word.length();
        Node* r = root;
        for(int i=0;i<sz;i++){
            char c = word[i];
            if(r->children.find(c)!= r->children.end()){
                r = r->children[c];
            }else{
                Node* NN = new Node();
                NN->value = c;
                r->children[c] = NN;
                r = NN;
            }
        }
        r->is_ends = true;
    }
    
    bool search(string &W) {
        int sz = W.length();
        Node* r = root;
        for(int i=0;i<sz;i++){
            if(W[i]!= '.'){
                if(r->children.find(W[i])== r->children.end()) return false;
                else r = r->children[W[i]];
            }else{
                for(char option = 'a';option<='z';option++){
                    W[i] = option;
                    if(search(W)) {
                        return true;
                    }
                    W[i]= '.';
                }
                return false;
            }
        }
        if(r!= NULL && r->is_ends == true) return true;
        return false;
    }
};
