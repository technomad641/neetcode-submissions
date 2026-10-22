class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // [2, -1, 1 , 2] k=2
        // [2, 1, 2, 4] i, j
        // prefix[i]- prefix[j-1] = k; lets i<=j
        // prefix[i]-k = prefix[j-1];
        map<int, int > cnt;
        cnt[0]=1;
        int s =0;
        int ans = 0;
        for(auto x: nums){
            s+=x;
            ans+= cnt[s-k];
            cnt[s]++;
            //cnt[s-k]++;
        }
        return ans;
        
    }
};