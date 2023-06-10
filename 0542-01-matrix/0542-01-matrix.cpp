class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // to find nearest 0 for each cell. find the nearest 0 for each 0 cell
        // this is multisouce bfs problem
        int m=mat.size();
        int n=mat[0].size();
                queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    visited[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dirX[]={-1,0,1,0};
        int dirY[]={0,1,0,-1};
        while(!q.empty()){
            pair<int,int> currNode=q.front();
            q.pop();
            int row=currNode.first;
            int col=currNode.second;
            for(int i=0;i<4;i++){
                int newRow=row+dirX[i];
                int newCol=col+dirY[i];
                if(newRow>=0 && newCol>=0 && newCol<n && newRow<m && visited[newRow][newCol]==-1){
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=visited[row][col]+1;
                }
            }
        }
        return visited;
        
        
    }
};