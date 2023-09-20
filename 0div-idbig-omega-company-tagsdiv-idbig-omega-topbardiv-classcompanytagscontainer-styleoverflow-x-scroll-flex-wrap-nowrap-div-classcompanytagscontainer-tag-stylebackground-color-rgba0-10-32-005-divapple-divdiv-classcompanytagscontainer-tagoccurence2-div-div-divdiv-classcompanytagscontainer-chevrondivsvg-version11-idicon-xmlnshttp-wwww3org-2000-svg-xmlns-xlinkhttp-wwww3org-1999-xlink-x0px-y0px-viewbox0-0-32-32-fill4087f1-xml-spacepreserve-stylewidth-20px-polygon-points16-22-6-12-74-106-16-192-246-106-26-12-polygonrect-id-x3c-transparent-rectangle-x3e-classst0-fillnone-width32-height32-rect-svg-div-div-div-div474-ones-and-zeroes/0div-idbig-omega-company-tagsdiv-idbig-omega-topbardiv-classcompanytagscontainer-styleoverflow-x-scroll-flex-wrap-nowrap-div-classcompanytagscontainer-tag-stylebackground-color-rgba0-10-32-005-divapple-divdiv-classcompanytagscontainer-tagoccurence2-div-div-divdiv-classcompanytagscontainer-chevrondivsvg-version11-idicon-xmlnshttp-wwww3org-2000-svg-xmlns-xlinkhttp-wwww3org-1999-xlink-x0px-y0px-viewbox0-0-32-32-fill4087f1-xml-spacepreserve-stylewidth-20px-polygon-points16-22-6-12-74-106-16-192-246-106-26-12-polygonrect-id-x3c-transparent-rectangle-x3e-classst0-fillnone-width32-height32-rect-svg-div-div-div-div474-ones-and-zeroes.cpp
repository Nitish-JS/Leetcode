class Solution {
public:
    pair<int,int> count(string s){
        int zeros=0;
        int ones=0;
        for(char c:s){
            if(c=='0')
                zeros++;
            else
                ones++;
        }
        return {zeros,ones};
    }
    
    int solve(vector<string> &strs,int m,int n,int index,vector<vector<vector<int>>> &dp){
        if(index<0){
            return 0;
        }
        if(dp[index][m][n]!=-1)
            return dp[index][m][n];
        pair<int,int> p=count(strs[index]);
        int take=0;
        if(p.first<=m && p.second<=n){
            
            take=1+solve(strs,m-p.first,n-p.second,index-1,dp);
        }
        int nottake=solve(strs,m,n,index-1,dp);
        return dp[index][m][n]=max(take,nottake);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,strs.size()-1,dp);
    }
};