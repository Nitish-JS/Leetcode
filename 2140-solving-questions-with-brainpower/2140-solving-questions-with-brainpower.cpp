class Solution {
public:
    //memoization
    // long long solve(vector<vector<int>> &questions,vector<long long> &dp,int index){
    //     if(index>=questions.size())
    //         return 0;
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     long long take=questions[index][0]+solve(questions,dp,index+questions[index][1]+1);
    //     long long nottake=0+solve(questions,dp,index+1);
    //     return dp[index]=max(take,nottake);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,0);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            long long nextQues=i+questions[i][1]+1;
            long long take=questions[i][0]+(nextQues<n?dp[nextQues]:0);
            long long nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[0];
        // return solve(questions,dp,0);
    }
};