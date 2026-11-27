class Solution {
public:
    int ans = 0;
    int local_ans = 0;
    //map< vector< int > , int > cnt;
    bool canHit(vector< int > A, vector< int > B){
        long x = abs(A[0]-B[0]);
        long y = abs(A[1]-B[1]);
        long z = A[2];
       return x*x + y*y <=z*z;
    }
    void dfs(int v, vector<vector<int>>&gr,  unordered_map< int, int >&vis){
        vis[v] =1;
        local_ans+= 1;
        for(auto &x: gr[v]){
            if(vis[x]==0) dfs(x, gr, vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //sort(begin(bombs), end(bombs));
        int n = bombs.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && canHit(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            local_ans = 0;
            unordered_map< int, int > vis;
            dfs(i, adj, vis);
            ans = max(ans, local_ans);
        }
        return ans;
        
    }
};
