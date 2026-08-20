class Solution {
public:
    vector<vector<int>>ans;
    unordered_map< int , int > vis;
    void dfs(vector<int>& nums, vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(auto x: nums){
            if(vis.find(x)!= vis.end()) continue;
            vis[x]=1;
            temp.push_back(x);
            dfs(nums, temp);
            temp.pop_back();
            vis.erase(x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        dfs(nums, temp);
        return ans;
    }
};
