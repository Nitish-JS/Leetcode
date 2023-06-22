class Solution {
public:
    int solve(vector<int> &prices,int fee,int index,int buy,vector<vector<int>> &dp){
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int take,nottake;
        if(buy){
            take=-prices[index]+solve(prices,fee,index+1,0,dp);
            nottake=0+solve(prices,fee,index+1,1,dp);
        }
        else{
            take=prices[index]-fee+solve(prices,fee,index+1,1,dp);
            nottake=0+solve(prices,fee,index+1,0,dp);
        }
        return dp[index][buy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,fee,0,1,dp);
    }
};