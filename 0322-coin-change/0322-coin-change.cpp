class Solution {
public:
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(index==0)
            return amount%coins[index]==0?amount/coins[index]:1e9;
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int nottake=solve(index-1,amount,coins,dp);
        int take=INT_MAX;
        if(coins[index]<=amount)
            take=1+solve(index,amount-coins[index],coins,dp);
        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int index=1;index<n;index++){
            for(int coin=0;coin<=amount;coin++){
                int nottake=dp[index-1][coin];
                int take=INT_MAX;
                if(coins[index]<=coin){
                    take=1+dp[index][coin-coins[index]];
                    // coin=coin-coins[index];
                }
                dp[index][coin]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        return ans==1e9?-1:ans;
    }
};