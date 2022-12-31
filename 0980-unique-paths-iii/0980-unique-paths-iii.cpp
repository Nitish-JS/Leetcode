class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,int empty){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2){
            return empty==-1?1:0;
        }
        grid[i][j]=-1;
        empty--;
        int left=solve(i,j-1,grid,empty);
        int right=solve(i,j+1,grid,empty);
        int top=solve(i-1,j,grid,empty);
        int bottom=solve(i+1,j,grid,empty);
        grid[i][j]=0;
        return left+right+top+bottom;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> start;
        int empty=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    start=make_pair(i,j);
                else if(grid[i][j]==0)
                    empty++;
            }
        }
        return solve(start.first,start.second,grid,empty);
    }
};