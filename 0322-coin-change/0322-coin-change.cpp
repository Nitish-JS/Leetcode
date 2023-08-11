class Solution {
public:
    int solve(vector<int> &coins,int index,int amount,vector<vector<int>> &dp){
        if(index==0){
            return amount%coins[index]==0?amount/coins[index]:1e9;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+solve(coins,index,amount-coins[index],dp);
        }
        int nottake=0+solve(coins,index-1,amount,dp);
        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins,coins.size()-1,amount,dp);
        return ans==1e9?-1:ans;
    }
};