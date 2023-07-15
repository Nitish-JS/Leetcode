class Solution {
public:
    int solve(vector<int>&nums,int target,int index,vector<int> &dp){
        if(index==nums.size()-1)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int ans=INT_MIN;
        for(int i=index+1;i<nums.size();i++){
            if(abs(nums[i]-nums[index])<=target){
                ans=max(ans,1+solve(nums,target,i,dp));
            }
        }
        return dp[index]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int ans=solve(nums,target,0,dp);
        return ans>0?ans:-1;
    }
};