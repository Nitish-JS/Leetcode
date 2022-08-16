class Solution {
public:
    void rotate(vector<vector<int>> & mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            rotate(mat);
            if(mat==target)
                return true;
        }
        return false;
    }
};