class Solution {
public:
    int solve(int index,vector<int> &dp){
        int mod=1e9+7;
        if(index<0)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int take=solve(index-2,dp);
        int nottake=solve(index-1,dp);
        return dp[index]=(take+nottake)%mod;
    }
    int countHousePlacements(int n) {
        vector<int> dp(n,-1);
       long long ans=solve(n-1,dp);
        int mod=1e9+7;
        return (ans*ans)%mod;
    }
};