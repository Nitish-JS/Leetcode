//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int grp;
	double x, y;
	double distance; 
};

/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
	int grp;
	double x, y;
	double distance; 
};
*/
// function should return to which grp 
// the test data will belong
int classifyAPoint(Point arr[], int n, int k, Point test);

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    Point arr[n], test;
	    for(int i=0; i<n ; i++)
	        cin>>arr[i].x>>arr[i].y>>arr[i].grp;
	   cin>>test.x>>test.y>>k;
	   cout<<classifyAPoint(arr, n, k, test)<<endl;
	}
	return 0;
}

// } Driver Code Ends


/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
	int grp;
	double x, y;
	double distance; 
};
*/
// function should return to which grp 
// the test data will belong
void calculateDistance(Point &a,Point &b){
    a.distance=pow(a.x-b.x,2)+pow(a.y-b.y,2);
    
}
bool sortPointsComparator(Point a,Point b){
    if(a.distance<b.distance)
        return true;
    return false;
}
int classifyAPoint(Point arr[], int n, int k, Point test)
{
    
    for(int i=0;i<n;i++){
        calculateDistance(arr[i],test);
    }
    sort(arr,arr+n,sortPointsComparator);
    unordered_map<int,int> um;
    for(int i=0;i<k;i++){
        um[arr[i].grp]++;
    }
    
    int maxi=INT_MIN;
    int ans=0;
    for(auto it:um){
        if(it.second>maxi){
            maxi=it.second;
            ans=it.first;
        }
    }
    return ans;
    // Code here
}