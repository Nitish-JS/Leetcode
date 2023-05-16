class Solution {
public:
    bool check(vector<vector<int>> &matrix,int row,int col,int num){
        for(int i=0;i<matrix.size();i++){
            if(matrix[row][i]==num && col!=i)
                return false;
            if(matrix[i][col]==num && row!=i)
                return false;
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(!check(matrix,i,j,matrix[i][j]))
                    return false;
            }
        }
        return true;
    }
};