class Solution {
public:
    int solve(int index,vector<int> &cost,vector<int> &dp){
        if(index>=cost.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int onestep=solve(index+1,cost,dp);
        int twostep=solve(index+2,cost,dp);
        return dp[index]=cost[index]+min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        int startZero=solve(0,cost,dp);
        fill(dp.begin(),dp.end(),-1);
        int startOne=solve(1,cost,dp);
        return min(startZero,startOne);
    }
};