class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &dp){
        if(row==grid.size()-1)
            return grid[row][col];
        if(row>=grid.size() || col>grid[row].size())
            return 1e5;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int down=solve(grid,row+1,col,dp);
        int leftdown=solve(grid,row+1,col+1,dp);
        return dp[row][col]=grid[row][col]+min(down,leftdown);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,dp);
    }
};