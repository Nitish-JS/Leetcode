class Solution {
public:
    bool solve(vector<int> &nums,int index,int sum,vector<int> &dp){
        if(sum==0)
            return true;
        if(index==0){
            return nums[0]==sum;
        }
        if(sum<0)
            return false;
        if(dp[sum]!=-1)
            return dp[sum];
        bool take=false;
        
        if(nums[index]<=sum){
            take=solve(nums,index-1,sum-nums[index],dp);
        }
        bool nottake=solve(nums,index-1,sum,dp);
        return dp[sum]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        vector<int> dp(200001,-1);
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0)
            return false;
        return solve(nums,nums.size()-1,sum/2,dp);
    }
};