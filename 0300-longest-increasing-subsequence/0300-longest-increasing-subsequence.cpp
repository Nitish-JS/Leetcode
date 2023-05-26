class Solution {
public:
    int solve(int index,int prev,vector<int>&nums,vector<vector<int>> &dp){
        if(index>=nums.size())
            return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev])
            pick=1+solve(index+1,index,nums,dp);
        int notpick=0+solve(index+1,prev,nums,dp);
        return dp[index][prev+1]=max(pick,notpick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
       return solve(0,-1,nums,dp);
    }
};