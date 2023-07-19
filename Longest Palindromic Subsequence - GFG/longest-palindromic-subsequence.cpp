//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string &A,string &B,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0;
        if(A[i]==B[j]){
            take=1+lcs(A,B,i-1,j-1,dp);
        }
        int nottake=max(lcs(A,B,i-1,j,dp),lcs(A,B,i,j-1,dp));
        return dp[i][j]=max(take,nottake);
    }
    int longestPalinSubseq(string A) {
        //code here
        string rev=A;
        vector<vector<int>> dp(A.size()+1,vector<int>(A.size()+1,0));
        reverse(rev.begin(),rev.end());
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=rev.size();j++){
                if(A[i-1]==rev[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[A.size()][A.size()];
        return lcs(A,rev,A.size()-1,rev.size()-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends