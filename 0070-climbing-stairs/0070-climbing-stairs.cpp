class Solution {
public:
    int solve(int index,int n,vector<int> &dp){
        if(index>=n-1)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int oneStep=solve(index+1,n,dp);
        int twoStep=solve(index+2,n,dp);
        return dp[index]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(0,n,dp);
    }
};