class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(i<0 || i>=grid.size() || j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
            return -100;
        if(i==grid.size()-1){
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int k=-1;k<=1;k++){
            for(int k1=-1;k1<=1;k1++){
                if(j1==j2){
                    maxi=max(grid[i][j1]+solve(i+1,j1+k,j2+k1,grid,dp),maxi);
                }
                else
                    maxi=max(grid[i][j1]+grid[i][j2]+solve(i+1,j1+k,j2+k1,grid,dp),maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solve(0,0,grid[0].size()-1,grid,dp);
    }
};