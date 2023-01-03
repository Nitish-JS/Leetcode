class Solution {
public:
    bool solve(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1,vector<bool>(200001,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool take=false;
            if(arr[index]<=target)
                take=dp[index-1][target-arr[index]];
            bool nottake=dp[index-1][target];
            dp[index][target]=take||nottake;
        }
    }
    return dp[n-1][k];
    // Write your code here.
}
//     bool solve(vector<int> &nums,int index,int sum,vector<int> &dp){
//         if(sum==0)
//             return true;
//         if(index==0){
//             return nums[0]==sum;
//         }
//         if(sum<0)
//             return false;
//         if(dp[sum]!=-1)
//             return dp[sum];
//         bool take=false;
        
//         if(nums[index]<=sum){
//             take=solve(nums,index-1,sum-nums[index],dp);
//         }
//         bool nottake=solve(nums,index-1,sum,dp);
//         return dp[sum]=take||nottake;
//     }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0)
            return false;
        return solve(nums.size(),sum/2,nums);
    }
};