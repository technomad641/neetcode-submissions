class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue< int , vector< int>, greater<int> >PQ;
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            PQ.push(nums[i]);
            if(i>=k) PQ.pop();
        }
        return PQ.top();
    }
};
