class Solution {
public:
    bool solve(string &str,string &pattern,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0)
            return true;
        if(j<0 && i>=0)
            return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==pattern[j] || pattern[j]=='?')
            return dp[i][j]=solve(str,pattern,i-1,j-1,dp);
        if(pattern[j]=='*')
            return dp[i][j]=solve(str,pattern,i-1,j,dp) || solve(str,pattern,i,j-1,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
        
    }
};