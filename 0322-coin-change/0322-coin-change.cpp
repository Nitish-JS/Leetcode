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
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        return ans==1e9?-1:ans;
    }
};