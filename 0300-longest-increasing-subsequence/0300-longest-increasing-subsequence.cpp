class Solution {
public:
    // int solve(int index,int prev,vector<int>&nums,vector<vector<int>> &dp){
    //     if(index>=nums.size())
    //         return 0;
    //     if(dp[index][prev+1]!=-1){
    //         return dp[index][prev+1];
    //     }
    //     int take=0;
    //     if(prev==-1 || nums[prev]<nums[index]){
    //         take=1+solve(index+1,index,nums,dp);
    //     }
    //     int nottake=0+solve(index+1,prev,nums,dp);
    //     return dp[index][prev+1]=max(take,nottake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        vector<int> curr(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int prev=index-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || nums[prev]<nums[index]){
                    take=1+dp[index+1];
                }
                int nottake=0+dp[prev+1];
                dp[prev+1]=max(take,nottake);
            }
            curr=dp;
        }
        return dp[-1+1];
    }
};