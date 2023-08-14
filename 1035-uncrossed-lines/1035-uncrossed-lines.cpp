class Solution {
public:
    int solve(vector<int> &nums1,vector<int> &nums2,int i,int j,vector<vector<int>> &dp){
        if(i<0 ||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0;
        if(nums1[i]==nums2[j])
            take=1+solve(nums1,nums2,i-1,j-1,dp);
        int nottake=max(solve(nums1,nums2,i-1,j,dp),solve(nums1,nums2,i,j-1,dp));
        return dp[i][j]=max(take,nottake);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return solve(nums1,nums2,nums1.size()-1,nums2.size()-1,dp);
    }
};      