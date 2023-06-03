class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return 1;
        if(i<0|| j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=solve(i,j-1,dp);
        int down=solve(i-1,j,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i!=0 || j!=0){
                    int right=0;
                    if(j>0)
                        right=dp[i][j-1];
                    int down=0;
                    if(i>0)
                        down=dp[i-1][j];
                    dp[i][j]=right+down;
                }
               
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1,n-1,dp);
        
    }
};