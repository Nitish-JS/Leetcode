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
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++ ){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
        return solve(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};