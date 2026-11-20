class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int sz = nums.size();
        for(int i=0;i<=sz-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int start = i+1;
            int end = sz-1;
            while(end-start>=1 ){
                if(nums[start] == nums[start-1] && start>(i+1)){
                    ++start; continue;
                }
                if(nums[start]+ nums[end] == target){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    --end;
                    ++start;
                }else{
                    if(nums[start]+ nums[end] > target){
                        --end;
                    }else {
                        ++start;
                    }
                }
            }

        }
        return ans;
    }
};
