class Solution {
public:
    void recurPermute(vector<int> &permArray,vector<int> &nums, vector<vector<int>> &ans,int freq[]){
       if(permArray.size()==nums.size()){
           ans.push_back(permArray);
           return;
       }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                permArray.push_back(nums[i]);
                freq[i]=1;
                recurPermute(permArray,nums,ans,freq);
                permArray.pop_back();
                freq[i]=0;
                // recurPermute(permArray,nums,ans,freq);
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permArray;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        recurPermute(permArray,nums,ans,freq);
        return ans;
    }
};