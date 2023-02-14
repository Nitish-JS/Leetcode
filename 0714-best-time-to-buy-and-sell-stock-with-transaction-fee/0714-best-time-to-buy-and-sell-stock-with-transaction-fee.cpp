class Solution {
public:
    int solve(int index,vector<int>&prices,int buy,int fee,vector<vector<int>> &dp){
        int profit;
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy){
            profit=max(-prices[index]+solve(index+1,prices,0,fee,dp),0+solve(index+1,prices,1,fee,dp));
        }
        else{
            profit=max(prices[index]+solve(index+1,prices,1,fee,dp)-fee,0+solve(index+1,prices,0,fee,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,1,fee,dp);
    }
};