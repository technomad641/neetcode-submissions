class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<vector<int>>ans;
        set<vector<int>> P;
        sort(begin(nums), end(nums));
        for(int i=0;i<sz;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<sz;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int a = j+1;
                int b = sz-1;
                vector< int > sol;
                while(a<b){
                     long long T = nums[i]+nums[j];
                    T+=nums[a];
                 T+=nums[b];
                    if(T == target){
                        ans.push_back({nums[i], nums[j], nums[a], nums[b]});
                        a++; 
                        b--;
                        while(a < b && nums[a]==nums[a-1])a++;
                        while(a < b && nums[b]==nums[b+1])b--;
                    }
                    else if(T < target) ++a;
                    else --b;
                }
            }
        }
        //for(auto x: P) ans.push_back(x);
        return ans;

    }
};