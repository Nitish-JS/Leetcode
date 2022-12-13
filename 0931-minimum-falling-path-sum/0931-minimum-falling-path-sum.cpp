class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size()));
        int ans=INT_MAX;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<col;i++)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(j==0)
                    dp[i][j]=min(dp[i-1][j+1]+matrix[i][j],dp[i-1][j]+matrix[i][j]);
                else if(j==col-1)
                    dp[i][j]=min(dp[i-1][j-1]+matrix[i][j],dp[i-1][j]+matrix[i][j]);
                else{
                    dp[i][j]=min(min(dp[i-1][j-1]+matrix[i][j],dp[i-1][j]+matrix[i][j]),dp[i-1][j+1]+matrix[i][j]);
                }
            }
        }
        for(int x:dp[dp.size()-1]){
            ans=min(ans,x);
        }
        return ans;
    }
};