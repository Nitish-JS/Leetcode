class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
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
        int dirY[]={0,-1,0,1};
        while(!q.empty()){
            pair<int,int> currNode=q.front();
            q.pop();
            int row=currNode.first;
            int col=currNode.second;
            for(int i=0;i<4;i++){
                int nextRow=row+dirX[i];
                int nextCol=col+dirY[i];
                if(nextRow>=0 && nextRow<m && nextCol>=0 && nextCol<n && visited[nextRow][nextCol]==-1){
                    q.push({nextRow,nextCol});
                    visited[nextRow][nextCol]=visited[row][col]+1;
                }
            }
        }
        return visited;
    }
};