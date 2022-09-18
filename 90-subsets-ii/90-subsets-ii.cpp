class Solution {
public:
    vector<vector<int>> ans;
    void subset(int index,vector<int>subseq,vector<int>nums){
        // if(index==nums.size()){
            ans.push_back(subseq);
            // return ;
        // }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            subseq.push_back(nums[i]);
            subset(i+1,subseq,nums);
            subseq.pop_back();
            // subset(index+1,subseq,nums);

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subseq;
        sort(nums.begin(),nums.end());
        subset(0,subseq,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};