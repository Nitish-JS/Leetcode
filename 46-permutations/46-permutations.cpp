class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recurPermute(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> permArray;
        // int freq[nums.size()];
        // for(int i=0;i<nums.size();i++){
        //     freq[i]=0;
        // }
        recurPermute(0,nums,ans);
        return ans;
    }
};