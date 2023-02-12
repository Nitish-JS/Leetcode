class Solution {
public:
    bool solve(int index,int target,vector<int> &arr,vector<int> &dp){
        if(target==0)
           return true;
        if(index==0)
            return arr[index]==target;
        if(dp[target]!=-1)
            return dp[target];
        bool take=false;
        if(arr[index]<=target)
            take=solve(index-1,target-arr[index],arr,dp);
        bool nottake=solve(index-1,target,arr,dp);
        return dp[target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1)
            return false;
        vector<int> dp(sum,-1);
        return solve(nums.size()-1,sum/2,nums,dp);
    }
};