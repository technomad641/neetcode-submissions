class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int count =1;
        int pos = 0;
        for(int i=0;i<sz;i++){
            if(i>0 && nums[i]==nums[i-1]) {
                if(count ==2 ){
                    //count = 1;
                    continue;
                }else{
                    nums[pos++]= nums[i];
                    ++count;
                }
            }else{
                count=1;
                nums[pos++]= nums[i];
            }
        }
        return pos;
    }
};