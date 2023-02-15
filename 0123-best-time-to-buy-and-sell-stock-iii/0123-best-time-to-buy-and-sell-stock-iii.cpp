class Solution {
public:
    int solve(int index,int buy,int bought,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(bought==0)
            return 0;
        if(index>=prices.size())
            return 0;
        if(dp[index][buy][bought]!=-1)
            return dp[index][buy][bought];
        int take=0, nottake=0;
        if(buy){
            take=max(-prices[index]+solve(index+1,0,bought,prices,dp),0+solve(index+1,1,bought,prices,dp));
        }
        else{
            nottake=max(prices[index]+solve(index+1,1,bought-1,prices,dp),0+solve(index+1,0,bought,prices,dp));
        }
        return dp[index][buy][bought]=max(take,nottake);
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};