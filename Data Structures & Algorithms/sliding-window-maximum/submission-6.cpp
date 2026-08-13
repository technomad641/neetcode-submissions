class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> ans;
        deque< int > Q;
        for(int i=0;i<sz;i+=1){
            while(!Q.empty() && nums[Q.back()]<=nums[i]) Q.pop_back(); // maintain the order
            while(!Q.empty() && i-Q.front()>=k) Q.pop_front(); // remove elements out of K
            //while(!Q.empty() && i-Q.front()>=k) Q.pop_front();
            Q.push_back(i);
            if(i>=k-1)ans.push_back(nums[Q.front()]); // now insert

        }
        return ans;
    }
};
