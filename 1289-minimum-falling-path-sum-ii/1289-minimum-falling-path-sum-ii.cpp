class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col,int n,vector<vector<int>> &dp){
        if(row>=n || col>=n || col<0)
            return 1e6;
        if(row==n-1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(i!=col){
                int points=grid[row][col]+solve(grid,row+1,i,n,dp);
                ans=min(ans,points);
            }
        }
        return dp[row][col]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(grid,0,i,n,dp));
        }
        return ans;
    }
};