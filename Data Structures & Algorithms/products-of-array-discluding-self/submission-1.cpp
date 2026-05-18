class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector< int > ans(sz+2, 1);
        vector< int > left(sz+2, 1);
        vector< int > right(sz+2, 1);
        for(int i=1;i<=sz;i++){
            left[i]= left[i-1]*nums[i-1];
            right[sz-i+1]=right[sz-i+2]*nums[sz-i];
            // cout<< right[sz-i];
            // cout<<endl;
            // cout<< left[i];
            // cout<<endl;
        }
        vector< int > sol;
        for(int i=1;i<=sz;i++){
            sol.push_back(left[i-1]* right[i+1]);
        }
        return sol;
    }
};
