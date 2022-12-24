class Solution {
public:
    int numTilings(int n) {
        if(n==0)
            return 0;
        long long dp[n+1];
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int mod=1e9;
        mod+=7;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3]);
            dp[i]%=mod;
        }
        return dp[n];
    }
};