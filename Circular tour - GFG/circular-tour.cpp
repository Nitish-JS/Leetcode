//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
        int start=0;
        int extra=0;
        int req=0;
        for(int i=0;i<n;i++){
            extra+=(p[i].petrol-p[i].distance);
            if(extra<0){
                start=i+1;
                req+=extra;
                extra=0;
            }
        }
        if(extra+req>=0) return start;
        return -1;
       //Your code here
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends