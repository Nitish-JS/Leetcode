class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int n=grid.size();
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        queue<vector<int>> q;
        q.push({1,0,0});
        distance[0][0]=1;
        while(!q.empty()){
            vector<int> curr=q.front();
            int row=curr[1];
            int col=curr[2];
            int dis=curr[0];
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nextRow=i+row;
                    int nextCol=j+col;
                    if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<n && grid[nextRow][nextCol]==0){
                        if(dis+1<distance[nextRow][nextCol]){
                            distance[nextRow][nextCol]=1+dis;
                            q.push({distance[nextRow][nextCol],nextRow,nextCol});
                        }
                    }
                }
            }
        }
        return distance[n-1][n-1]==INT_MAX?-1:distance[n-1][n-1];
        
        
    }
};