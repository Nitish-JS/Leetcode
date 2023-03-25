class Solution {
public:
    int maxSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<mat[0].size()-2;j++){
                    sum=mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                    ans=max(ans,sum);
            
        }
    }
    return ans;
    }
};