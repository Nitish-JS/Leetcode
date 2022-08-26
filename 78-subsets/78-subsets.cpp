class Solution {
public:
    vector<vector<int>> ans;
    void subset(int index,vector<int> subseq,vector<int> nums){
        if(index>=nums.size()){
            ans.push_back(subseq);
            return;
        }
        subseq.push_back(nums[index]);
        subset(index+1,subseq,nums);
        subseq.pop_back();
        subset(index+1,subseq,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subseq;
        subset(0,subseq,nums);
            return ans;
    }
};