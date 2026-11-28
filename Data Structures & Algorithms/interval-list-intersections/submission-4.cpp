class Solution {
public:
    bool overlaps(int x1, int y1, int x2, int y2){
            if(x2 > y1) return false;
            if(x1 > y2) return false;
            return true;
    }

    vector<int> findIntersection(int x1, int y1, int x2, int y2){
            return {max(x1, x2), min(y1, y2)};
    }

    bool shouldIncrementFirst(int x1, int y1, int x2, int y2){
        return y1 < y2;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>  ans;
        int sz1 = firstList.size();
        int sz2 = secondList.size();
        sort(begin(firstList), end(firstList));
        sort(begin(secondList), end(secondList));
        int i=0;
        int j=0;
        while(i< sz1 && j<sz2){ // till the list exhausts

        if(overlaps(firstList[i][0],firstList[i][1],secondList[j][0], secondList[j][1])){
            ans.push_back(findIntersection(firstList[i][0],firstList[i][1],secondList[j][0], secondList[j][1]));
        }
        
        if(shouldIncrementFirst(firstList[i][0],firstList[i][1],secondList[j][0], secondList[j][1])) i++;
        else ++j;
        
        //case:1   check if it overlaps
            // if yes, find intersectioon and push to ans
            // else increment either i or j

        // case 2:   increment either i or j

        }
        return ans;
    }
};