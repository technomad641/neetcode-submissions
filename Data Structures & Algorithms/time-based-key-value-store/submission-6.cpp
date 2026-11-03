class TimeMap {
public:
    map< string, vector< int > >cnt;
        map< string, map<int, string >>val;
    TimeMap() {
        cnt.clear();
        val.clear();
    }
    
    void set(string key, string value, int timestamp) {
        //cnt[key][value].push_back(timestamp);
        cnt[key].push_back(timestamp);
        val[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(val[key].find(timestamp)!= val[key].end()){
            return val[key][timestamp];
        }
        vector< int > value = cnt[key];
        int l=0;
        int h = value.size()-1;
        int ans = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(value[m]<=timestamp){
                l=m+1;
                ans = m;
            }else h=m-1;
        }
        if(ans == -1) return "";
        return val[key][value[ans]];
    }
};
