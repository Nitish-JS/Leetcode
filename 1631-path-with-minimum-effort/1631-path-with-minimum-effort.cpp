class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
        pq.push({0,{0,0}});
        int maxTillNow=INT_MIN;
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
                return dis;
            for(int i=0;i<4;i++){
                int nextRow=row+dirX[i];
                int nextCol=col+dirY[i];
                if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m){
                    int maxTillNow=max(dis,abs(heights[nextRow][nextCol]-heights[row][col]));
                    if(maxTillNow<distance[nextRow][nextCol]){
                        distance[nextRow][nextCol]=maxTillNow;
                        pq.push({maxTillNow,{nextRow,nextCol}});
                    }
                }
            }
        }
        return -1;
    }
};