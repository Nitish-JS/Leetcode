class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp){
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size())
            return 1;
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=solve(i,j+1,obstacleGrid,dp);
        int bottom=solve(i+1,j,obstacleGrid,dp);
        return dp[i][j]=right+bottom;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return solve(0,0,obstacleGrid,dp);
    }
};