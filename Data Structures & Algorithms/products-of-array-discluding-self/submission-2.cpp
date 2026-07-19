class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector< int > cnt(sz, 1);
        for(int i=sz-1;i>=0;i--){
            int P=1 ;
            if(i==sz-1) P= nums[i];
            else P = cnt[i+1]*nums[i];
            cnt[i]= P;
        }
        vector< int > sol;
        int rn=1;
        for(int i=0;i<sz;i++){
            if(i==0) {
                if(i+1<sz) sol.push_back(cnt[i+1]);
                else sol.push_back(nums[i]);
            }else{
                if(i+1<sz)sol.push_back(rn*cnt[i+1]);
                else sol.push_back(rn);
            }
            rn*=nums[i];
        }
        return sol;
    }
};
