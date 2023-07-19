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
        vector<vector<int>> dp(A.size()+1,vector<int>(A.size()+1,-1));
        reverse(rev.begin(),rev.end());
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