class Solution {
public:
    // int solve(int index,vector<int> &dp){
    //     if(index<=0)
    //         return 1;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     int oneStep=solve(index-1,dp);
    //     int twoStep=solve(index-2,dp);
    //     return dp[index]=oneStep+twoStep;
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,0);
        if(n<=1)
            return 1;
        int prev2=1;
        int prev1=1;
        int ans;
        for(int index=2;index<=n;index++){
            ans=prev1+prev2;
            prev2=prev1;
            prev1=ans;
        }
       return ans;
    }
};