class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &nums,int index,int k,vector<int> &ds){
        if(index==nums.size() || ds.size()==k){
            if(ds.size()==k){
                ans.push_back(ds);
            }
            return ;
        }
        ds.push_back(nums[index]);
        solve(ans,nums,index+1,k,ds);
        ds.pop_back();
        solve(ans,nums,index+1,k,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,nums,0,k,ds);
        return ans;
        
        
    }
};