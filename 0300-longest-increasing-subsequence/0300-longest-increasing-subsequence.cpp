class Solution {
public:
    int solve(int index,int prev,vector<int>&nums,vector<vector<int>> &dp){
        if(index>=nums.size())
            return 0;
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int take=0;
        if(prev==-1 || nums[prev]<nums[index]){
            take=1+solve(index+1,index,nums,dp);
        }
        int nottake=0+solve(index+1,prev,nums,dp);
        return dp[index][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(0,-1,nums,dp);
    }
};