class Solution {
public:
    unordered_map< int, int > dp;
    int recur(int index, int sz, vector<int>& nums){
        if(index<0 || index>sz) return dp[index]=0;
        if(index == sz) return dp[index]=nums[index];
       // if(index == sz-1) return nums[index];
        //cout<<index<<endl;
        if(dp.find(index)!= dp.end()) return dp[index];
        int taken = nums[index] + recur(index+2, sz,  nums);
        int left = recur(index+1, sz, nums);
        //cout<< taken<<" "<<left<<endl;
        return dp[index]= max(left, taken);
    }
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[sz-1];
        int taken1 = recur(0, sz-2,  nums);
        dp.clear();
        int taken2 = recur(1, sz-1, nums);
        dp.clear();
        return max(taken1, taken2);
    }
};
