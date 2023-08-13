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
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
        }
        for(int index=1;index<coins.size();index++){
            for(int money=0;money<=amount;money++){
                int take=INT_MAX;
                if(coins[index]<=money)
                    take=1+dp[index][money-coins[index]];
                int nottake=dp[index-1][money];
                dp[index][money]=min(take,nottake);
            }
        }
        return dp[coins.size()-1][amount]==1e9?-1:dp[coins.size()-1][amount];
        int ans=solve(coins,coins.size()-1,amount,dp);
        return ans==1e9?-1:ans;
    }
};