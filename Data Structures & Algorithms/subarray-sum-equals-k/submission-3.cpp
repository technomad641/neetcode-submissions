class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        int ans =0;
        map< int, int > seen;
        
        vector< int >prefixSum(sz+1, 0);
        //prefixSum[0]=1;
        seen[0]=1;
        for(int i=1;i<=sz;i++){
            prefixSum[i]= prefixSum[i-1]+ nums[i-1];
            ans+=seen[prefixSum[i]-k];
            seen[prefixSum[i]]++;
        }
        
        return ans;
    }
};



// prefixSum[j]-prefixSum[i] = K;
// j>i && j<=nums.size();
// i >=0
// prefixSum[j] -K = prefixSum[i]
// find count of (PrefixSum[j]-k)
// Sum of count
