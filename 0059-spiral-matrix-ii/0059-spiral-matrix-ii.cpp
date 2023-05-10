class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int row_start=0;
        int row_end=n-1;
        int col_start=0;
        int col_end=n-1;
        int number=1;
        while(row_start<=row_end && col_start<=col_end){
            for(int i=col_start;i<=col_end;i++){
                matrix[row_start][i]=number++;
            }
            row_start++;
            for(int i=row_start;i<=row_end;i++){
                matrix[i][col_end]=number++;
            }
            col_end--;
            if(row_start<row_end){
                for(int i=col_end;i>=col_start;i--){
                    matrix[row_end][i]=number++;
                }
                row_end--;
            }
            if(col_start<col_end){
                for(int i=row_end;i>=row_start;i--){
                    matrix[i][col_start]=number++;
                }
                col_start++;
            }
        }
        return matrix;
    }
};