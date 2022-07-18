class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row_sum=0;
        int max_row_sum=0;
        for(int i=0;i<accounts.size();i++){
            for(int j=0;j<accounts[i].size();j++){
                row_sum+=accounts[i][j];
            }
            max_row_sum=max(row_sum,max_row_sum);
            row_sum=0;
        }
        return max_row_sum;
    }
};