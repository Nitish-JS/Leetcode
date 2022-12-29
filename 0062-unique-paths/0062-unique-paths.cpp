class Solution {
public:
    // int solve(int i,int j,int m,int n,vector<vector<int>> &dp){
    //     if(i==m-1 && j==n-1)
    //         return 1;
    //     if(i>m-1 || j>n-1)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int right=solve(i,j+1,m,n,dp);
    //     int bottom=solve(i+1,j,m,n,dp);
    //     return dp[i][j]=right+bottom;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j]=1;
                else{
                    int left=0,top=0;
                    if(j>0)
                        left=dp[i][j-1];
                    if(i>0)
                        top=dp[i-1][j];
                    dp[i][j]=left+top;
                }
            }
        }
        return dp[m-1][n-1];
    }
};