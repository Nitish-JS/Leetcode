class Solution {
public:
    void transpose(vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i<j)
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
            
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        transpose(matrix);
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};