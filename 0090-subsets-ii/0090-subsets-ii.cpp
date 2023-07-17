class Solution {
public:
    
    void powerSet(vector<int> &nums,int index,set<vector<int>> &ans,vector<int> &subset){
        if(index<0){
            ans.insert(subset);
            return ;
        }
        subset.push_back(nums[index]);
        powerSet(nums,index-1,ans,subset);
        subset.pop_back();
        powerSet(nums,index-1,ans,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        powerSet(nums,nums.size()-1,ans,subset);
        vector<vector<int>> subsets(ans.begin(),ans.end());
        return subsets;
    }
};