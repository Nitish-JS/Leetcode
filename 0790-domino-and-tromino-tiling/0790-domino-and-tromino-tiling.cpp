class Solution {
public:
    int numTilings(int n) {
        int mod=1e9;
        mod+=7;
        long long dp[1001];
        memset(dp,0,sizeof dp);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n<=3)
            return dp[n];
        for(int i=4;i<=n;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=mod;
        }
        return dp[n];
    }
};