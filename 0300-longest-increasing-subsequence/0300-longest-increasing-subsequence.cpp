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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                if(j==-1 || nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                int nottake=0+dp[i+1][j+1];
                dp[i][j+1]=max(take,nottake);
            }
        }
        return dp[0][-1+1];
        return solve(nums,0,-1,dp);
    }
};