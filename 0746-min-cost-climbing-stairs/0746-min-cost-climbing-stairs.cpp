class Solution {
public:
    // int solve(int index,vector<int> &cost,vector<int> &dp){
    //     if(index>=cost.size())
    //         return 0;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     int onestep=solve(index+1,cost,dp);
    //     int twostep=solve(index+2,cost,dp);
    //     return dp[index]=cost[index]+min(onestep,twostep);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=cost[0];
        int prev1=cost[1];
        int cur;
        for(int i=2;i<n;i++){
            cur=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=cur;
        }
        return min(prev1,prev2);
    }
};