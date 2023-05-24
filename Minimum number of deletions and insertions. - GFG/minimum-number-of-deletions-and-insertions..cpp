//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    int lcs=0;
	    vector<int> curr(m+1,0);
	    vector<int> prev(m+1,0);
	    
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(str1[i-1]==str2[j-1]){
	                curr[j]=1+prev[j-1];
	                lcs=max(lcs,curr[j]);
	            }
	            else{
	                curr[j]=max(prev[j],curr[j-1]);
	            }
	        }
	        prev=curr;
	    }
	   // cout<<lcs;
	    return n+m-2*lcs;
	    // Your code goes here
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends