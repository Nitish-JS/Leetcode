class Solution {
public:
    void solve(vector<vector<int>> &combinations,vector<int> &combination,int index,int n,int k){
        if(index==n){
            if(combination.size()==k)
                combinations.push_back(combination);
            return ;
        }
        combination.push_back(index);
        solve(combinations,combination,index+1,n,k);
        combination.pop_back();
        solve(combinations,combination,index+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        solve(combinations,combination,1,n+1,k);
        return combinations;
    }
};