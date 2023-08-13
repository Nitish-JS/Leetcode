class Solution {
public:
    bool isSafe(int row,int col,int n,int m){
        if(row<0 || row>=n || col<0 || col>=m)
            return false;
        return true;
    }
    int solve(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &dp){
        if(!isSafe(row,col,grid.size(),grid[0].size()))
            return 0;
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        int take=INT_MIN;
        if(dp[row][col]!=-1)
            return dp[row][col];
        for(int i=0;i<4;i++){
            int path=0;
            int nextRow=row+dirX[i];
            int nextCol=col+dirY[i];
            if(isSafe(nextRow,nextCol,grid.size(),grid[0].size()) && grid[row][col]<grid[nextRow][nextCol]){
                path=1+solve(grid,nextRow,nextCol,dp);
            }
            take=max(take,path);
        }
        return dp[row][col]=take;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=INT_MIN;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans+1;
    }
};