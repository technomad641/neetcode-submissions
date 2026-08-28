class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int st = 0;
        int en = arr.size()-1;
        while(st< en && en-st+1 != k){
            int leftdiff = abs(arr[st]-x);
            int rightdiff = abs(arr[en]-x);
            if(leftdiff>rightdiff) ++st;
            else --en;
        }
        vector< int > ans;
        for(int i=st;i<=en;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};