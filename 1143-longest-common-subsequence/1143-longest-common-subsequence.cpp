class Solution {
public:
    int solve(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0;
        if(text1[i]==text2[j])
            take=1+solve(text1,text2,i-1,j-1,dp);
        int nottake=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
        return dp[i][j]=max(take,nottake);
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};