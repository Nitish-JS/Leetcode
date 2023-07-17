//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> &arr,int index,int sum,vector<int> &ans){
        if(index<0){
            ans.push_back(sum);
            return;
        }
        solve(arr,index-1,sum+arr[index],ans);
        solve(arr,index-1,sum,ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr,N-1,0,ans);
        return ans;
        
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends