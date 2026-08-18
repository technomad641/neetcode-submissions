class TimeMap {
public:
    map<string, map<int, string>> M;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        M[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (M.find(key) == M.end())
            return "";

        auto& T = M[key];

        auto it = T.upper_bound(timestamp);

        if (it == T.begin())
            return "";

        --it;

        return it->second;
    }
};