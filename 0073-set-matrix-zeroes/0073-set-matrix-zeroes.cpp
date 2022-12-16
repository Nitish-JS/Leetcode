class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    vp.push_back({i,j});
            }
        }
        // cout<<matrix.size();
        // for(auto it:vp){
        //     cout<<it.first<<" "<<it.second<<'\n';
        // }
        for(auto it:vp){
            int row=it.first;
            for(int i=0;i<matrix[0].size();i++){
                matrix[row][i]=0;
            }
            int col=it.second;
            for(int i=0;i<matrix.size();i++){
                matrix[i][col]=0;
            }
        }
    }
};