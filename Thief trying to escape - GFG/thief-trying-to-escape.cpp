//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int totalJumps(int X, int Y, int N, int arr[]){
        // code here
        int ans=0;
        for(int i=0;i<N;i++){
            if(arr[i]<=X)
                ans++;
            else{
                int actualJump=X-Y;
                arr[i]-=Y;
                ans+=arr[i]/actualJump;
                int rem=arr[i]%actualJump;
                if(rem>0)
                    ans++;
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int X, Y, N;
        cin>>X>>Y>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.totalJumps(X, Y, N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends