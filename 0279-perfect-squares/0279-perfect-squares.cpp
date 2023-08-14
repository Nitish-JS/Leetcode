class Solution {
public:
    int solve(vector<int> &squares,int index,int target,vector<vector<int>> &dp){
     
        if(index==0){
            if(target==0)
                return 0;
            if(target%squares[index]==0)
                return target/squares[index];
            return 1e5;
        }
        if(dp[index][target]!=-1)
            return dp[index][target];
        int take=INT_MAX;
        if(squares[index]<=target){
            take=1+solve(squares,index,target-squares[index],dp);
        }
        int nottake=0+solve(squares,index-1,target,dp);
        return dp[index][target]=min(take,nottake);
        
        
    }
    int numSquares(int n) {
       vector<int> squares;
        for(int i=1;i<=n;i++){
            if(sqrt(i)==floor(sqrt(i)))
                squares.push_back(i);
        }
        vector<vector<int>> dp(squares.size(),vector<int>(n+1,-1));
        return solve(squares,squares.size()-1,n,dp);
        
    }
};