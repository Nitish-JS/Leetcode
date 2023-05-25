class Solution {
public:
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        if(i<0)
          return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
        int insert=1+solve(word1,word2,i,j-1,dp);
        int del=1+solve(word1,word2,i-1,j,dp);
        int replace=1+solve(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(insert,min(del,replace));

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};