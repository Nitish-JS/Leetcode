class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // count no of ones
        int oneCount=0;
        int n=grid.size();
        int m=grid[0].size();
        //copying the input matrix
        vector<vector<int>> mat(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=grid[i][j];
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                else if(mat[i][j]==1)
                    oneCount++;
            }
        }
        if(!oneCount)
            return 0;
        int time=0;
        int curOneCount=0;
        vector<int> rows={-1,0,1,0};
        vector<int> cols={0,-1,0,1};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> node=q.front();
                q.pop();
                int currRow=node.first;
                int currCol=node.second;
                for(int i=0;i<4;i++){
                    int nextRow=currRow+rows[i];
                    int nextCol=currCol+cols[i];
                    if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m && mat[nextRow][nextCol]==1){
                        q.push({nextRow,nextCol});
                        mat[nextRow][nextCol]=2;
                        curOneCount++;
                    }
                }
            }
            time++;
        }
        if(oneCount!=curOneCount)
            return -1;
        return time-1;
    }
};