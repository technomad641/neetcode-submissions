class Solution {
public:
    bool isSafe(int k, int h){
        return k<=h;
    }

    int findTotal(int k, vector<int>& piles){
        int hours = 0;
        for(auto &x: piles){
            if(x%k==0) hours+=x/k;
            else{
                hours+=(x/k +1);
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high = 1000000000*10;
        int ans = 1;
        while(low<=high){
            int m = low+(high-low)/2;
            if(isSafe(findTotal(m, piles),h)){
                ans = m;
                high = m-1;
            }else low = m+1;
        }
        return ans;
    }
};
