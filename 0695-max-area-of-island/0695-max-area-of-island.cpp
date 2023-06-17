class Solution {
public:
    int maxDepth=INT_MIN;
    // void dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int depth,int row,int col){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     visited[row][col]=1;
    //     maxDepth=max(depth,maxDepth);
    //     int dirX[]={-1,0,1,0};
    //     int dirY[]={0,-1,0,1};
    //     for(int i=0;i<4;i++){
    //         int nextRow=row+dirX[i];
    //         int nextCol=col+dirY[i];
    //         if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m && grid[nextRow][nextCol]==1 && visited[nextRow][nextCol]==0){
    //             dfs(grid,visited,depth+1,nextRow,nextCol);
    //         }
    //     }
    // }
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        visited[row][col]=1;
        int depth=1;
        while(!q.empty()){
            pair<int,int> currNode=q.front();
            q.pop();
            int currRow=currNode.first;
            int currCol=currNode.second;
            for(int i=0;i<4;i++){
                int nextRow=currRow+dirX[i];
                int nextCol=currCol+dirY[i];
                    if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m && grid[nextRow][nextCol]==1 && visited[nextRow][nextCol]==0){
                        q.push({nextRow,nextCol});
                        depth++;
                         visited[nextRow][nextCol]=1;
                    }
                }
            }
        maxDepth=max(depth,maxDepth);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    bfs(grid,visited,i,j);
                }
            }
        }
        return maxDepth==INT_MIN?0:maxDepth;
        
    }
};