//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int start,int end,vector<vector<int>> &dp){
        if(start==end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int minSteps=INT_MAX;
        for(int k=start;k<end;k++){
            int steps=arr[start-1]*arr[k]*arr[end]+solve(arr,start,k,dp)+solve(arr,k+1,end,dp);
            minSteps=min(steps,minSteps);
        }
        return dp[start][end]=minSteps;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(arr,1,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends