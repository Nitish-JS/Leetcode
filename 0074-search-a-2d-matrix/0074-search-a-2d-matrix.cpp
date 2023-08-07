class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int row_low=0,row_high=m;
        while(row_low<=row_high){
            int col_low=0,col_high=n;
            int row_mid=row_low+(row_high-row_low)/2;
            if(matrix[row_mid][0]>target)
                row_high=row_mid-1;
            else if(matrix[row_mid][0]<=target)
                row_low=row_mid+1;
            while(col_low<=col_high){
                int col_mid=col_low+(col_high-col_low)/2;
                if(matrix[row_mid][col_mid]==target)
                    return true;
                else if(matrix[row_mid][col_mid]>target)
                    col_high=col_mid-1;
                else
                    col_low=col_mid+1;
            }
        }
        return false;
    }
};