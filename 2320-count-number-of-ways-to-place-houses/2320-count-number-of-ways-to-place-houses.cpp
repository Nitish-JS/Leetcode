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
        long prev2=1;
        long prev=2;
        for(int i=2;i<=n;i++){
            long curr=(prev+prev2)%mod;
            prev2=prev;
            prev=curr;
        }
       
        return (prev*prev)%mod;
    }
};