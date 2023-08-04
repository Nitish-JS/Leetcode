//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &prices,int index,int buy,vector<vector<int>> &dp){
        if(index==prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int take=0;
        if(buy){
            take=-1*prices[index]+solve(prices,index+1,0,dp);
        }
        else
            take=prices[index]+solve(prices,index+1,1,dp);
        int nottake=0+solve(prices,index+1,buy,dp);
        return dp[index][buy]=max(take,nottake);
        
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends