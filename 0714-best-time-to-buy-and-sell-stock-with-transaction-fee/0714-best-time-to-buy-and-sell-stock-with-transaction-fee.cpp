class Solution {
public:
//     recursion + memoization
    // int solve(vector<int> &prices,int fee,int index,int buy,vector<vector<int>> &dp){
    //     if(index>=prices.size())
    //         return 0;
    //     if(dp[index][buy]!=-1)
    //         return dp[index][buy];
    //     int take,nottake;
    //     if(buy){
    //         take=-prices[index]+solve(prices,fee,index+1,0,dp);
    //         nottake=0+solve(prices,fee,index+1,1,dp);
    //     }
    //     else{
    //         take=prices[index]-fee+solve(prices,fee,index+1,1,dp);
    //         nottake=0+solve(prices,fee,index+1,0,dp);
    //     }
    //     return dp[index][buy]=max(take,nottake);
    // }
    int maxProfit(vector<int>& prices, int fee) {
//         tabulation
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int take,nottake;
                if(buy){
                    take=-prices[index]+dp[index+1][0];
                    nottake=0+dp[index+1][1];
                }
                else{
                    take=prices[index]-fee+dp[index+1][1];
                    nottake=0+dp[index+1][0];
                }  
                dp[index][buy]=max(take,nottake);
            }
        }
        return dp[0][1];
        // return solve(prices,fee,0,1,dp);
    }
};