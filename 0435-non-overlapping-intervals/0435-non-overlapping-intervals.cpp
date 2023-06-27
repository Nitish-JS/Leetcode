class Solution {
public:
    static bool comparator(vector<int> &v1,vector<int> &v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        int j=0,n=intervals.size();
        int overLappedInterval=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=intervals[j][1]){
                j=i;
            }
            else{
                overLappedInterval++;
            }
        }
        return overLappedInterval;
    }
};