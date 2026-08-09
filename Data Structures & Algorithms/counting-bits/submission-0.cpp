class Solution {
public:
    int numberOnes(int x){
        int cnt =0;
        for(int i=0;i<32;i++){
            if(x&(1<<i))++cnt;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector< int > ans;
        for(int i=0;i<=n;i++){
            ans.push_back(numberOnes(i));
        }
        return ans;
    }
};
