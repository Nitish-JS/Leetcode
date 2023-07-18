class Solution {
public:
    void combinations(vector<int> &nums,int target,int index,vector<vector<int>> &ans,vector<int> &ds){
        if(index==nums.size()){
            if(target==0)
                ans.push_back(ds);
            return ;
        }
        if(nums[index]<=target){
            ds.push_back(nums[index]);
            combinations(nums,target-nums[index],index,ans,ds);
            ds.pop_back();
        }
        combinations(nums,target,index+1,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(nums,target,0,ans,ds);
        return ans;
    }
};