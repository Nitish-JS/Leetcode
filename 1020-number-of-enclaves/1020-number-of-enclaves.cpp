class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int newRow=row+dirX[i];
            int newCol=col+dirY[i];
            if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && !visited[newRow][newCol] && grid[newRow][newCol]==1)
                dfs(grid,visited,newRow,newCol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !visited[i][0])
                dfs(grid,visited,i,0);
            if(grid[i][n-1]==1 && !visited[i][n-1])
                dfs(grid,visited,i,n-1);
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !visited[0][i])
                dfs(grid,visited,0,i);
            if(grid[m-1][i]==1 && !visited[m-1][i])
                dfs(grid,visited,m-1,i);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<visited[i][j]<<" ";
                if(grid[i][j]==1 && visited[i][j]==0)
                    ans++;
            }
            // cout<<"\n";
        }
        return ans;
    }
};