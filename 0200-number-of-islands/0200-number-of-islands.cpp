class Solution {
public:
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited,int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            pair<int,int> node=q.front();
            int currRow=node.first;
            int currCol=node.second;
            q.pop();
            if(currRow-1>=0 && currRow-1<grid.size() && grid[currRow-1][currCol]=='1' && (visited[currRow-1][currCol]==0) ){
                q.push({currRow-1,currCol});
                visited[currRow-1][currCol]=1;
            }
            if(currRow+1>=0 && currRow+1<grid.size() && grid[currRow+1][currCol]=='1' && (visited[currRow+1][currCol]==0) ){
                q.push({currRow+1,currCol});
                visited[currRow+1][currCol]=1;
            }
            if(currCol-1>=0 && currCol-1<grid[0].size() && grid[currRow][currCol-1]=='1' && (visited[currRow][currCol-1]==0) ){
                q.push({currRow,currCol-1});
                visited[currRow][currCol-1]=1;
            }
            if(currCol+1>=0 && currCol+1<grid[0].size() && grid[currRow][currCol+1]=='1' && (visited[currRow][currCol+1]==0) ){
                q.push({currRow,currCol+1});
                visited[currRow][currCol+1]=1;
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};