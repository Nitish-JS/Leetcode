class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int newRow=row+dirX[i];
            int newCol=col+dirY[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol]==0 && grid[newRow][newCol]==0){
                dfs(grid,visited,newRow,newCol);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
                dfs(grid,visited,i,0);
            if(grid[i][m-1]==0)
                dfs(grid,visited,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)
                dfs(grid,visited,0,i);
            if(grid[n-1][i]==0)
                dfs(grid,visited,n-1,i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 &&  grid[i][j]==0){
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};