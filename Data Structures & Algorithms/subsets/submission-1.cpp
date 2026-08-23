class Solution {
public:
    vector<vector<int>>ans;
    void recur(int index, vector< int> temp, vector<int>& nums){
        if(index == nums.size()) return;

        // take the current index
        temp.push_back(nums[index]);
        ans.push_back(temp);
        recur(index+1, temp, nums);
        temp.pop_back();

        // leave the current index
        recur(index+1, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< int> temp;
        ans.push_back(temp);
        recur(0, temp, nums);
        return ans;
    }
};
