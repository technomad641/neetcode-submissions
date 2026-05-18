class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector< int > > ans;
        vector< int > temp;
        backtrack(ans, temp, nums, 0);
        return ans;    
    }

    void backtrack( vector< vector< int > >&ans,vector< int> temp,
    vector< int> nums, int index){
            ans.push_back(temp);
            int sz = nums.size();
            for(int i = index;i< sz;i++){
                temp.push_back(nums[i]);
                backtrack(ans, temp, nums, i+1);
                temp.pop_back();
            }
    }
};
