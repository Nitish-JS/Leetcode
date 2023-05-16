class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||  grid[i][j]==0)
            return 0;
        int val=grid[i][j];
        grid[i][j]=0;
        int u=val+solve(i-1,j,grid,dp);
        int d=val+solve(i+1,j,grid,dp);
        int l=val+solve(i,j-1,grid,dp);
        int r=val+solve(i,j+1,grid,dp);
        grid[i][j]=val;
        int ans=max(l,max(u,max(r,d)));
        return dp[i][j]=ans;

       
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) continue;
                int x=solve(i,j,grid,dp);
                maxi=max(maxi,x);
                // cout<<x<<" ";
            }
            cout<<endl;
        }
        return maxi;

    }
};