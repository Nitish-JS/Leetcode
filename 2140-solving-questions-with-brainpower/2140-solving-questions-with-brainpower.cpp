class Solution {
public:
    long long solve(vector<vector<int>> &questions,vector<long long> &dp,int index){
        
        if(index>=questions.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        long long take=questions[index][0]+solve(questions,dp,index+questions[index][1]+1);
        long long nottake=0+solve(questions,dp,index+1);
        return dp[index]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        return solve(questions,dp,0);
    }
};