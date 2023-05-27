class Solution {
public:
    // int solve(int index,int n,vector<int> &dp){
    //     if(index<0)
    //         return 0;
    //     if(index==0)
    //         return 1;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     int oneStep=solve(index-1,n,dp);
    //     int twoStep=solve(index-2,n,dp);
    //     return dp[index]=oneStep+twoStep;
    // }
    int climbStairs(int n) {
        int prev1=1;
        int prev2=0;
        int ans;
        for(int i=1;i<=n;i++){
            ans=prev1+prev2;
            prev2=prev1;
            prev1=ans;
        }
        return ans;
        // return solve(0,n,dp);
    }
};