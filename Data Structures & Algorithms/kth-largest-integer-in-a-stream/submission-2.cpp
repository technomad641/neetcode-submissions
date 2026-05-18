class KthLargest {
public:
    priority_queue< int, vector< int > , greater<> > pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
               K=k;
              int sz = nums.size();
              for(int i=0;i<sz;i++){
                pq.push(nums[i]);
                if(pq.size()>K) pq.pop();
              }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();
    }
};


// 1 4 2 5 6 7 3 2


// 1 2 4 5