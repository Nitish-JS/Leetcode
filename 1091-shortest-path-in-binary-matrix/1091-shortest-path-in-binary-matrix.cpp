class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> directions={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int length=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==n-1 && col==n-1)
                    return length;
                for(auto dir:directions){
                    int nextX=row+dir[0];
                    int nextY=col+dir[1];
                    if(nextX>=0 && nextX<=n-1 && nextY>=0 && nextY<=n-1 && grid[nextX][nextY]==0){
                        q.push({nextX,nextY});
                        grid[nextX][nextY]=1;
                    }
                }
                
            }
            length++;
        }
        return -1;
    }
};