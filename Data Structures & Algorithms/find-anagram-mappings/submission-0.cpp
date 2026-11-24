class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map< int , int > cnt;
        vector<int>ans;
        int sz = nums2.size();
        for(int i=0;i<sz;i++) cnt[nums2[i]]=i;
        sz = nums1.size();
        for(int i=0;i<sz;i++){
            ans.push_back(cnt[nums1[i]]);
        }
        return ans;
    }
};
