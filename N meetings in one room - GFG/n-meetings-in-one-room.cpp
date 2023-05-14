//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    typedef struct meeting{
        int start;
        int end;
        int pos;
    };
    static bool comparator( meeting m1,meeting m2){
        if(m1.end<m2.end)
            return true;
        if(m1.end>m2.end)
            return false;
        if(m1.pos>m2.pos)
            return false;
        return true;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        meeting m[n];
        for(int i=0;i<n;i++){
            m[i].start=start[i];
            m[i].end=end[i];
            m[i].pos=i+1;
        }
        sort(m,m+n,comparator);
        int ans=1;
        int current_end=m[0].end;
        // for(int i=0;i<n;i++){
        //     cout<<m[i].start<<" "<<m[i].end<<"\n";
        // }
        for(int i=1;i<n;i++){
            if(m[i].start>current_end){
                current_end=m[i].end;
                ans++;
            }
        }
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends