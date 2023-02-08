class Solution {
public:
    int solve(int index,vector<int> &dp){
        if(index<0)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int take=solve(index-2,dp);
        int nottake=solve(index-1,dp);
        return dp[index]=(take+nottake)%1000000007;
    }
    int countHousePlacements(int n) {
        int mod=1e9+7;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
       
        return (dp[n]*dp[n])%mod;
    }
};