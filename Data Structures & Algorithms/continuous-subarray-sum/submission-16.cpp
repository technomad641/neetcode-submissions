class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        vector< int > prefixS(sz+1);
        vector< int > prefixMod(sz+1);
        map<int, int>m;
        for(int i=0;i<sz;i++){
            prefixS[i+1] = prefixS[i]+ nums[i];
        }
        for(int i=1;i<=sz;i++){
            prefixMod[i]= prefixS[i]%k;
        }
        m[0] = 0;
        for(int i=1;i<=sz;i++){
            if(m.find(prefixMod[i])!= m.end()){
                if(i-m[prefixMod[i]]>=2 ) return true;
            }
            else m[prefixMod[i]]=i;
        }
        return false;

    }
};