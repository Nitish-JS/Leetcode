class Solution {
public:
    int solve(vector<int> &nums,int index,int prev_index,vector<vector<int>> &dp){
        if(index==nums.size())
            return 0;
        if(dp[index][prev_index+1]!=-1)
            return dp[index][prev_index+1];
        int take=0;
        if(prev_index==-1 || nums[index]>nums[prev_index])
            take=1+solve(nums,index+1,index,dp);
        int nottake=0+solve(nums,index+1,prev_index,dp);
        return dp[index][prev_index+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};