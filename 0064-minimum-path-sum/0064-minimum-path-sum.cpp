class Solution {
public:
    // int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp){
    //     if(i==0 && j==0)
    //         return grid[0][0];
    //     if(i<0 || j<0)
    //         return 1000;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int left=grid[i][j]+solve(grid,i,j-1,dp);
    //     int right=grid[i][j]+solve(grid,i-1,j,dp);
    //     return dp[i][j]=min(left,right);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else{
                    int left=grid[i][j],up=grid[i][j];
                    if(j>0)
                        left+=dp[i][j-1];
                    else
                        left+=10000;
                    if(i>0)
                        up+=dp[i-1][j];
                    else
                        up+=10000;
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};