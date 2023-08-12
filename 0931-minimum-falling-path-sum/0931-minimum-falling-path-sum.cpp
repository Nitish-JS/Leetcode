class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &dp){
        if(row>grid.size() || col<0 || col>=grid[0].size())
            return 1e5;
        if(row==grid.size()-1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up=solve(grid,row+1,col,dp);
        int upleft=solve(grid,row+1,col-1,dp);
        int upright=solve(grid,row+1,col+1,dp);
        return dp[row][col]=grid[row][col]+min({up,upleft,upright});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     ans=min(ans,solve(matrix,0,i,dp));
        // }
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=matrix[i][j]+min({dp[i-1][j],dp[i-1][j+1]});
                }
                else if(j==n-1){
                    dp[i][j]=matrix[i][j]+min({dp[i-1][j],dp[i-1][j-1]});
                }
                else
                    dp[i][j]=matrix[i][j]+min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};