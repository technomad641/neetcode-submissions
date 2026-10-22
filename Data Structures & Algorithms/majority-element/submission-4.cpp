class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0;
        int prev = -34342;
        for(auto x: nums){
            if(prev == -34342){
                prev = x;
                ++cnt;
            }else{
                if(prev ==x) ++cnt;
                else{
                   if(cnt>0) --cnt;
                   else {
                    prev = x;
                    cnt = 1;}
                }
            }
        }
        return prev;
        
    }
};