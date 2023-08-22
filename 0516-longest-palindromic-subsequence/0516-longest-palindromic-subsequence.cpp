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
// public:
//     int lcs(string s1,string s2,int i,int j,vector<vector<int>> &dp){
//         if(i<0 ||j <0)
//             return 0;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int take=0;
//         if(s1[i]==s2[j])
//             return dp[i][j]=1+lcs(s1,s2,i-1,j-1,dp);
//         else
//             return dp[i][j]=max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         string s2=s;
//         reverse(s2.begin(),s2.end());
//         vector<vector<int>> dp(s.size()+1,vector<int>(s2.size()+1,-1));
//         return lcs(s,s2,s.size()-1,s2.size()-1,dp);
//     }
// };