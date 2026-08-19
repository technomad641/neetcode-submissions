class MyHashMap {
public:
    vector< int > hashset;
    MyHashMap() {
       hashset.resize(4000000, -1);
    }
    int hashfunction(int x){
        int MOD = 4000000;
        return (2*x+18)%MOD;
    }
    
    void put(int key, int value) {
        hashset[hashfunction(key)]= value;
    }
    
    int get(int key) {
        return hashset[hashfunction(key)];
    }
    
    void remove(int key) {
        hashset[hashfunction(key)] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */