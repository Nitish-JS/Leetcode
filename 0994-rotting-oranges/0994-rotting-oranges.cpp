class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int one_count=0;
        vector<vector<int>> mat(m,vector<int>(n));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=grid[i][j];
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    one_count++;
                }
            }
        }
        if(one_count==0)
            return 0;
        int disX[]={-1,0,1,0};
        int disY[]={0,-1,0,1};
        int new_one_count=0;
        int time=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> currNode=q.front();
                q.pop();
                int currRow=currNode.first;
                int currCol=currNode.second;
                for(int i=0;i<4;i++){
                    int newRow=currRow+disX[i];
                    int newCol=currCol+disY[i];
                    if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && mat[newRow][newCol]==1){
                        q.push({newRow,newCol});
                        mat[newRow][newCol]=2;
                        new_one_count++;
                    }
                }
            }
            time++;
        }
        if(new_one_count!=one_count)
            return -1;
        return time-1;
    }
};