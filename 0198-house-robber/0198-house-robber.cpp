class Solution {
public:
    int solve(int index,vector<int> &nums,vector<int> &dp){
        if(index<0)
            return 0;
        if(index==0)
            return nums[0];
        if(dp[index]!=-1)
            return dp[index];
        int take=nums[index]+solve(index-2,nums,dp);
        int nottake=0+solve(index-1,nums,dp);
        return dp[index]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=dp[i-2];
            }
            int nottake=0+dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[nums.size()-1];
    }
};