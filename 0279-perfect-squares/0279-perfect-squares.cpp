class Solution {
public:
    int solve(vector<int> &dp,int index,int target){
        if(target==0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        if(index*index<=target){
            return dp[target]=min(1+solve(dp,index,target-index*index),solve(dp,index+1,target));
        }
        return dp[target]=1e5;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(dp,1,n);
    }
};