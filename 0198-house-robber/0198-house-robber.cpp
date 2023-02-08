class Solution {
public:
    int solve(int index,vector<int> &nums,vector<int> &dp){
        if(index>=nums.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int take=nums[index]+solve(index+2,nums,dp);
        int nottake=0+solve(index+1,nums,dp);
        return dp[index]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};