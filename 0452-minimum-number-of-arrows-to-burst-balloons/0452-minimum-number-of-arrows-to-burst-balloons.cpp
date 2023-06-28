class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int n=points.size();
        int ans=1;
        int currEnd=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>currEnd){
                ans++;
                currEnd=points[i][1];
            }
        }
        return ans;
    }
};