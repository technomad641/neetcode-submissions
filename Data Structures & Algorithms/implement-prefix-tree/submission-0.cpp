class PrefixTree {
public:
    struct node{
        map< char, struct node* > nei;
        bool isend;
    };
    struct node* root;
    PrefixTree() {
        root = new node();
    }
    
    void insert(string word) {
        int sz = word.size();
        struct node* t = root;
        for(int i=0;i<sz;i++){
            if(t->nei.find(word[i])==t->nei.end()){
                struct node*p  = new node();
                t->nei[word[i]] =p;
                t = p;
            }else t = t->nei[word[i]];

            if(i == sz-1) t->isend = true;
        }
    }
    
    bool search(string word) {
        struct node* t = root;
        for(char x: word){
            if(t->nei.find(x)==t->nei.end()) return false;
            t = t->nei[x];
        }
        if(t->isend == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        struct node* t = root;
        for(char x: prefix){
            if(t->nei.find(x)==t->nei.end()) return false;
            t = t->nei[x];
        }
        
        return true;
    }
};
