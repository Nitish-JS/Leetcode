class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col){
        if(row==0 && col==0){
            return grid[0][0];
        }
        if(row<0 || col<0)
            return 1e5;
        int up=solve(grid,row-1,col);
        int left=solve(grid,row,col-1);
        return grid[row][col]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                int right=1e5;
                int down=1e5;
                if(j>0)
                    right=dp[i][j-1];
                if(i>0)
                    down=dp[i-1][j];
                dp[i][j]=grid[i][j]+min(right,down);
            }
        }
        return dp[m-1][n-1];
        return solve(grid,m-1,n-1);
    }
};