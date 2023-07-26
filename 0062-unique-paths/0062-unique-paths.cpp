class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1)
            return 1;
        if(i>=m || j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=solve(m,n,i,j+1,dp);
        int down=solve(m,n,i+1,j,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> curr(n,0);
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[0]=1;
                else{
                    int left=0;
                    int up=0;
                    if(i>0)
                        up=prev[j];
                    if(j>0)
                        left=curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return curr[n-1];
        return dp[m-1][n-1];
        return solve(m,n,0,0,dp);
    }
};