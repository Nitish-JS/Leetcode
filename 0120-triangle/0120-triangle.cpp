class Solution {
public:
     int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n,0);
        dp[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            vector<int> temp(n);
            for(int j=0;j<i+1;j++){
                int up=INT_MAX;
                if(j!=i){
                    up=triangle[i][j]+dp[j];
                }
                int diag=INT_MAX;
                if(j>0)
                    diag=triangle[i][j]+dp[j-1];
                temp[j]=min(up,diag);
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(dp[i],ans);
        }
        return ans;
    }
}; 