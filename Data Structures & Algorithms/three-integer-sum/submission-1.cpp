class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector< int > > ans;
        int  sz=nums.size();
        for(int i=0;i<sz-2;i++){
            if(i>0 && nums[i]== nums[i-1]) continue;
            vector< int >triplet;
            int a = i+1;
            int b = sz-1;
            while(a<b && b>=0 && a<sz){
                int S = nums[a]+ nums[b];
                if(S == -nums[i]){
                    ans.push_back({nums[i], nums[a], nums[b]});
                    while (a < b && nums[a] == nums[a + 1]) a++;
                    while (a < b && nums[b] == nums[b - 1]) b--;
                    a++; b--;
                }
                else if(S > -nums[i]) b--;
                else a++;
            }
        }
        return ans;
        
    }
};


// -1 0 1 2 -1 -4

// -4 -1 -1 0 1 2
//     i  a  b   

// target = -4
//  -1 +2 = 1

//  -1 + 1 =0


//  -1 

//  -1 +2 = 1


