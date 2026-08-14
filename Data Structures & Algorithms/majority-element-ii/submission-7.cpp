class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 =0;
        int sz = nums.size();
        vector< int > sol;
        for(auto x: nums){
            if(cnt1 == 0 && x!= num2){
                ++cnt1; 
                num1 = x;
            }else if(cnt2 == 0 && x!= num1){
                ++cnt2; 
                num2 = x;
            }else if(num1 == x){
                ++cnt1;
            }else if(num2 == x){
                ++cnt2;
            }else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(auto x: nums){
            if(x == num1) ++cnt1;
            else if(x == num2)++cnt2;
            
        }
        if(cnt1 >(sz/3)){sol.push_back(num1);}
        if(cnt2 >(sz/3)){sol.push_back(num2);}
        return sol;
    }
};