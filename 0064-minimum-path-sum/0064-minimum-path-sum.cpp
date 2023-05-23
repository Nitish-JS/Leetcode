class Solution {
public:
    // int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 ||j<0)
    //        return 1e5;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int up=grid[i][j]+solve(grid,i-1,j,dp);
    //     int left=grid[i][j]+solve(grid,i,j-1,dp);
    //     return dp[i][j]=min(up,left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> curr(n,0);
        vector<int> prev(n,0);
        // vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=grid[i][j];
                }
                else{
                    int up=INT_MAX;
                    int down=INT_MAX;
                    if(i>0){
                        up=grid[i][j]+prev[j];
                    }
                    if(j>0)
                        down=grid[i][j]+curr[j-1];
                    curr[j]=min(up,down);
                }
            }
            prev=curr;
        }
        return curr[n-1];
        // return solve(grid,m-1,n-1,dp);

    }
};