class Solution {
public:
    int solve(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>> &dp){
        if(n==0)
            return triangle[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=triangle[i][j]+solve(triangle,i+1,j,n-1,dp);
        int diag=triangle[i][j]+solve(triangle,i+1,j+1,n-1,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));  
        return solve(triangle,0,0,n-1,dp);
    }
}; 