class Solution {
public:
    // int solve(int n,int dp[]){
    //     if(n<0)
    //         return 0;
    //     if(n<=1)
    //         return dp[n]=n;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     else
    //         return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    int fib(int n) {
        // int dp[31];
        if(n<1)
            return n;
        int f2=0,f1=1;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=f2+f1;
            f1=f2;
            f2=ans;
        }
        return ans;
        // memset(dp,-1,sizeof(dp));
        // return solve(n,dp);
    }
};