class MyHashSet {
public:
    vector< int > hashset;
    MyHashSet() {
        hashset.resize(1000000, -1);
    }
    
    void add(int key) {
        hashset[key%1000000]= 1;
    }
    
    void remove(int key) {
        hashset[key%1000000] = -1;
    }
    
    bool contains(int key) {
        if(hashset[key%1000000]== -1) return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */