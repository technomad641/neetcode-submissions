class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int r = matrix.size();
        int j =matrix[0].size()-1;
        while(i<r && j>=0){
            if(matrix[i][j]==target) return 1;
            else{
                if(matrix[i][j]>target){
                    --j;
                }else{
                    ++i;
                }
            }
        }
        return 0;
    }
};
