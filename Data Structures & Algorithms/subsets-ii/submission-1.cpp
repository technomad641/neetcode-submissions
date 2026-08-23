class Solution {
public:
    set<vector<int>> ans;

    void recur(int index, vector<int> temp, vector<int>& nums) {
        if (index == nums.size()) return;

        // take
        temp.push_back(nums[index]);
        ans.insert(temp);
        recur(index + 1, temp, nums);
        temp.pop_back();

        // leave
        recur(index + 1, temp, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        ans.insert(temp);

        recur(0, temp, nums);

        vector<vector<int>> sol;
        for (auto x : ans)
            sol.push_back(x);

        return sol;
    }
};