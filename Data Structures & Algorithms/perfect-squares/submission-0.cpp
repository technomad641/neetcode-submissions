class Solution {
public:
    unordered_map< int, unordered_map<int, int > >dp;
    int minCount(int N, vector<int >&pre, int index){
            if(N ==0) return 0;
            if(N<0 || index==pre.size()) return 10001;
            if(dp.find(N)!= dp.end() && dp[N].find(index)!= dp[N].end()) return dp[N][index];
            int taken = 1+minCount(N-pre[index], pre, index);
            int left =  minCount(N, pre, index+1);
            return dp[N][index] = min(taken, left);
    }
    int numSquares(int n) {
        vector<int >pre;
        for(int i=1;i<=100;i++) pre.push_back(i*i);
        return minCount(n, pre, 0);
    }
};