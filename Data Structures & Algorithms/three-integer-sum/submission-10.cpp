class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>>ans;
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int a = i+1;
            int b = sz-1;
            while(a<sz && a<b){
                if(nums[a]+nums[b] == -nums[i]){
                    ans.push_back({nums[i], nums[a], nums[b]});
                    ++a; 
                    --b;
                    while(a<b && nums[a]==nums[a-1])++a;
                    while(a<b && nums[b]==nums[b+1])--b;
                }else if(nums[a]+nums[b] < -nums[i]) ++a;
                else --b;
            }
        }
        return ans;
    }
};

