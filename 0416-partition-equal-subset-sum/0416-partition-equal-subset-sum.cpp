class Solution {
public:
    bool solve(vector<int> &nums,int index,int target,vector<vector<int>> &dp){
        if(target==0)
            return false;
        if(index==0)
            return nums[index]==target;
        if(dp[index][target]!=-1)
            return dp[index][target];
        bool take=false;
        if(nums[index]<=target)
            take=solve(nums,index-1,target-nums[index],dp);
        bool nottake=solve(nums,index-1,target,dp);
        return dp[index][target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2==1)
            return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums,nums.size()-1,sum/2,dp);
        
    }
};