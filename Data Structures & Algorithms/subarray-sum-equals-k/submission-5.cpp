class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>m;
        m[0]=1;
        int ans =0;
        int s =0;
        for(auto x:nums){
            s+=x;
            ans+=m[s-k];
            m[s]++;
            
        }
        return ans;
    }
};