class Solution {
public:

    int canEat(vector< int > &piles, int k){
        int ans = 0;
        for(auto p: piles){
            ans+=(p)/k;
            if(p%k!=0) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(begin(piles), end(piles));
        int L = 1;
        int R = piles[piles.size()-1];
        int ans = R;
        while(L<=R){
            int m = L+(R-L)/2;
            if(h>=canEat(piles, m)){
                R = m-1;
                ans = m;
            }else{
                L = m+1;
                // ans = m-1;
                //ans = m;
            }
        }
        return ans;
    }
};
