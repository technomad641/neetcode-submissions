class KthLargest {
public:
    priority_queue< int, vector<int>, greater<int> >PQ;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int sz = nums.size();
        for(int i=0;i<sz;i++){
            PQ.push(nums[i]);
            if(i>=K) PQ.pop();
        }
    }
    
    int add(int val) {
        PQ.push(val);
        if(PQ.size()>K) PQ.pop();
        return PQ.top();
    }
};
