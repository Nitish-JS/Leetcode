class Solution {
public:
    int solve(int i,int j,string &s,string &rev,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==rev[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,rev,dp);
        }
        else
            return dp[i][j]=max(solve(i-1,j,s,rev,dp),solve(i,j-1,s,rev,dp));
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size(),-1));
        reverse(rev.begin(),rev.end());
        return solve(s.size()-1,s.size()-1,s,rev,dp);
        
    }
};