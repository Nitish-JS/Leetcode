class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        int sum=0;
        for(int i=0;i<n;i++){
            dp[0]+=nums[i]*i;
            sum+=nums[i];
        }
        int ans=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+sum-n*nums[n-i];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};