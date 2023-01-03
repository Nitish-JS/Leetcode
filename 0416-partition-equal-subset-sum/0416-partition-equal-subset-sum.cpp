class Solution {
public:
    bool solve(int n, int k, vector<int> &arr) {
    vector<bool>prev(200001,0);
    vector<bool> curr(200001,0);
    prev[0]=true;
    prev[arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool take=false;
            if(arr[index]<=target)
                take=prev[target-arr[index]];
            bool nottake=prev[target];
            curr[target]=take||nottake;
        }
        prev=curr;
    }
    return prev[k];
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