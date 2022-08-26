class Solution {
public:
    vector<vector<int>> ans;
    void subset(int index,vector<int>subseq,vector<int>nums){
        if(index>=nums.size()){
            sort(subseq.begin(),subseq.end());
            if(find(ans.begin(),ans.end(),subseq)==ans.end())
                ans.push_back(subseq);
            return ;
        }
        subseq.push_back(nums[index]);
        subset(index+1,subseq,nums);
        subseq.pop_back();
        subset(index+1,subseq,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subseq;
        subset(0,subseq,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};