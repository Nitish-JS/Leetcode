class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int one_count=0,two_count=0,zero_count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    two_count++;
                }
                else if(grid[i][j]==1)
                    one_count++;
                else
                    zero_count++;
            }
        }
        if(one_count==0)
            return 0;
        int ans=0;
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int currRow=q.front().first;
                int currCol=q.front().second;
                q.pop();
                if(currRow+1<grid.size() && grid[currRow+1][currCol]==1){
                    grid[currRow+1][currCol]=2;
                    q.push({currRow+1,currCol});
                }
                if(currCol+1<grid[0].size() && grid[currRow][currCol+1]==1){
                    grid[currRow][currCol+1]=2;
                    q.push({currRow,currCol+1});
                }
                if(currRow-1>=0  && grid[currRow-1][currCol]==1){
                    grid[currRow-1][currCol]=2;
                    q.push({currRow-1,currCol});
                }
                if(currCol-1>=0 && grid[currRow][currCol-1]==1){
                    grid[currRow][currCol-1]=2;
                    q.push({currRow,currCol-1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans-1;
        
        
        
    }
};