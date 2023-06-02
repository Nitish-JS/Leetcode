class Solution {
public:
    int solve(int index,int prev,vector<int>&nums,vector<vector<int>> &dp){
        if(index>=nums.size())
            return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev])
            pick=1+solve(index+1,index,nums,dp);
        int notpick=0+solve(index+1,prev,nums,dp);
        return dp[index][prev+1]=max(pick,notpick);
        
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
         int dp[n];
        fill(dp,dp+n,1);
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        for(int i:dp){
            maxi=max(maxi,i);
        }
        return maxi;
       //  vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
       // return solve(0,-1,nums,dp);
    }
};