class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs.size();
        int col=strs[0].size();
        vector<vector<char>> mat(row,vector<char>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]=strs[i][j];
            }
        }
        vector<vector<char>> transpose(col,vector<char>(row));
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                transpose[i][j]=mat[j][i];
            }
        }
        int ans=0;
        for(auto it:transpose){
            vector<char> temp=it;
            sort(temp.begin(),temp.end());
            if(temp!=it)
                ans++;
        }
        // for(auto it:strs){
        //     string temp=it;
        //     sort(temp.begin(),temp.end());
        //     if(temp!=it)
        //         ans++;
        // }
        return ans;
    }
};