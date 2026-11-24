class LRUCache {
public:
    list<int > L;
    unordered_map< int, int > CNT;
    unordered_map< int, list<int>::iterator > M;
    int max_size;
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if(M.find(key)== M.end()) return -1;
        list<int>:: iterator K = M[key];
        L.erase(K);
        L.push_front(key);
        M[key] = L.begin();
        return CNT[key];
    }
    
    void put(int key, int value) {
        if(M.find(key) != M.end()){
            L.erase(M[key]);
        }else{
            // size is over    
            if(L.size()== max_size){
                int key = L.back();
                L.pop_back();
                M.erase(key);
                CNT.erase(key);
            }
                if(M.find(key)!= M.end()){
                auto X = M[key];
                L.erase(X);
            }   
        }
        L.push_front(key);
            M[key] = L.begin();;
            CNT[key] = value; 
        

        

    }
};
