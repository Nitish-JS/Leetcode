class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &dp){
        if(row==0 && col==0)
            return 1;
        if(row<0 || col<0 || grid[row][col]==1)
            return 0;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up=solve(grid,row-1,col,dp);
        int left=solve(grid,row,col-1,dp);
        return dp[row][col]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,m-1,n-1,dp);
    }
};