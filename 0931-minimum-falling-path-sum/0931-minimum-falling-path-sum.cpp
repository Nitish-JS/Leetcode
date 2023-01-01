class Solution {
public:
    int solve(vector<vector<int>> &matrix,int i,int j,int n,vector<vector<int>> &dp){
        if(i>n || j<0 || j>n){
            return 10001;
        }
        if(i==n){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=matrix[i][j]+solve(matrix,i+1,j,n,dp);
        int leftdiag=matrix[i][j]+solve(matrix,i+1,j-1,n,dp);
        int rightdiag=matrix[i][j]+solve(matrix,i+1,j+1,n,dp);
        return dp[i][j]=min(down,min(leftdiag,rightdiag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            ans=min(ans,solve(matrix,0,i,n-1,dp));
        }
        return ans;
    }
};