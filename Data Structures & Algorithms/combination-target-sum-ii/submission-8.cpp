class Solution {
public:
map< vector<int>, int > ans;
vector<vector<int>> sol;
vector< int> vis;
    void dfs(vector<int>& nums, int target, int S, int i, vector<int>T){
        //if(i>=nums.size()) return;
        if(target ==0){
            sol.push_back(T);
            return;
        }
        if(target<0 || i==nums.size()) return;
        //if(vis[i]) return;
        int sz = nums.size();
        for(int j=i;j<sz;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            T.push_back(nums[j]);
            //vis[j]=1;
            target-=nums[j];
            dfs(nums, target, S, j+1, T);
            target+=nums[j];
            T.pop_back();
            //vis[j]=0;
            
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< int> T;
        vis.resize(101, 0);
        sort(begin(candidates), end(candidates));
        dfs(candidates, target, 0, 0, T);
        // for(auto x: ans){
        //     sol.push_back(x.first);
        // }
        return sol;
    }
};


