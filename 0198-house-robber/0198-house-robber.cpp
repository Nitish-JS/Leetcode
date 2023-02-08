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
        // vector<int> dp(nums.size(),0);
        int prev=nums[0];
        int prev2=NULL;
        // dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=0+prev;
            prev2=prev;
            prev=max(take,nottake);
        }
        return prev;
    }
};