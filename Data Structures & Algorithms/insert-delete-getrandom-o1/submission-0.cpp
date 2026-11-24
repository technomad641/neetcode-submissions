class RandomizedSet {
public:
    list< int > L;
    map< int, list< int> ::iterator > cnt;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(cnt.find(val)!= cnt.end()) return false;
        L.push_front(val);
        cnt[val] = L.begin();
        return true;
    }
    
    bool remove(int val) {
        if(cnt.find(val)== cnt.end()) return false;
        list< int > ::iterator R = cnt[val];
        L.erase(R);
        cnt.erase(val);
        return true;
    }
    
    int getRandom() {
        int sz = L.size();
        int randIndea = rand()%sz ;
        auto ans = L.begin();
        for(int i=1;i<randIndea;i++){
            ++ans;
        }
        return *ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */