class Solution {
public:
    int solve(vector<int> &nums,int left,int right,int chance,vector<vector<int>> &dp){
        if(left>right)
            return 0;
        if(dp[left][right]!=-1)
            return dp[left][right];
        if(chance==0)
            return dp[left][right]=min(solve(nums,left+1,right,1,dp),solve(nums,left,right-1,1,dp));
        else
            return dp[left][right]=max(nums[left]+solve(nums,left+1,right,0,dp),nums[right]+solve(nums,left,right-1,0,dp));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int alice=0;
        int bob=0;
        for(int i:nums)
            bob+=i;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        // vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        alice=solve(nums,0,nums.size()-1,1,dp);
        bob-=alice;
        cout<<alice<<" "<<bob<<'\n';

        return alice>=bob;
    }
};