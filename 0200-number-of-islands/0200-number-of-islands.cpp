class Solution {
public:
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited,int row,int col){
        int delX[]={-1,0,1,0};
        int delY[]={0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            int currRow=q.front().first;
            int currCol=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nextRow=currRow+delX[i];
                int nextCol=currCol+delY[i];
                if(nextRow>=0 && nextCol>=0 && nextRow<grid.size() && nextCol<grid[0].size() && visited[nextRow][nextCol]==0 && grid[nextRow][nextCol]=='1'){
                    q.push({nextRow,nextCol});
                    visited[nextRow][nextCol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    bfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};