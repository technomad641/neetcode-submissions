class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sz = arr.size();
        vector< int > incre(sz, 1);
        vector< int > dec(sz, 1);
        int ans = 1;
        for(int i=1;i<sz;i++){
            if(arr[i]> arr[i-1]){
                incre[i] = dec[i-1]+1;
            }else if(arr[i] < arr[i-1]){
                dec[i] = incre[i-1]+1;
            }
            ans = max(ans, max(incre[i], dec[i]));
        }
        return ans;
    }
};