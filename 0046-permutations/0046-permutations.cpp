class Solution {
public:
    void permute(vector<int>&nums,int index,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permute(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;      
        permute(nums,0,ans);
        return ans;
    }
};