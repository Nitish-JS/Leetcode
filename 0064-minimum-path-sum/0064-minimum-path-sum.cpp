class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 1e5;
        if(i==0 && j==0)
            return grid[0][0];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=grid[i][j]+solve(grid,i-1,j,dp);
        int left=grid[i][j]+solve(grid,i,j-1,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);

    }
};