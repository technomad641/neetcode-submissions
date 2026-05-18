class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int, int> m;
        int sz = nums.size();
        for(int i=0;i<sz; i++){
            if(m.find(target-nums[i])!=m.end() && i!= m[target-nums[i]]){
                return {m[target-nums[i]], i};
            }
            m[nums[i]]=i;
        }
        return {0, sz-1};
    }
};
