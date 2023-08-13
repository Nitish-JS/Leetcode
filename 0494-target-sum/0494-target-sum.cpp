class Solution {
public:
    int solve(vector<int>&nums,int index,int target,int currSum,vector<vector<int>> &dp){
        if(index<0){
            if(currSum==target)
                return 1;
            return 0;
        }
        if(dp[index][currSum+1000]!=-1)
            return dp[index][currSum+1000];
        int plus=solve(nums,index-1,target,currSum+nums[index],dp);
        int minus=solve(nums,index-1,target,currSum-nums[index],dp);
        return dp[index][currSum+1000]=minus+plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {  
        vector<vector<int>> dp(nums.size(),vector<int>(2*1000+1,-1));
        return solve(nums,nums.size()-1,target,0,dp);
    }
};