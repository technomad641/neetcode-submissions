class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
      //  int r = 0;
        int ans = INT_MAX;
        int s =0;
        int sz = nums.size();
        for(int r =0;r<sz;r++){
            s+=nums[r];
            cout<<s<<endl;
            while(l<=r && s>=target){
                //cout<< l<<" "<<r<<endl;
                ans = min(ans, r-l+1);
                s-=nums[l];
                ++l;
               // if(s<0) s= nums[r];
            }
        }
        return ans==INT_MAX ? 0: ans;
        
    }
};