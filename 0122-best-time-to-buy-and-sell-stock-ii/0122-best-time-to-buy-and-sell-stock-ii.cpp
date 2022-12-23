class Solution {
public:
    
    int solve(int index,int buy,vector<int> &prices,int dp[][2]){
        int profit;
        if(index==prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy){
            profit=max(-prices[index]+solve(index+1,0,prices,dp),0+solve(index+1,1,prices,dp));
        }
        else
            profit=max(prices[index]+solve(index+1,1,prices,dp),0+solve(index+1,0,prices,dp));
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2];
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices,dp);
    
    }
};