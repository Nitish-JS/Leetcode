class Solution {
public:
    // void powerSet(vector<int> &nums,int index,set<vector<int>> &ans,vector<int> &subset){
    //     if(index<0){
    //         ans.insert(subset);
    //         return ;
    //     }
    //     subset.push_back(nums[index]);
    //     powerSet(nums,index-1,ans,subset);
    //     subset.pop_back();
    //     powerSet(nums,index-1,ans,subset);
    // }
        void powerSet(vector<int> &nums,int index,vector<vector<int>> &ans,vector<int> &subset){
            ans.push_back(subset);
            for(int i=index;i>=0;i--){
                if(i<index && nums[i]==nums[i+1]) continue;
                subset.push_back(nums[i]);
                powerSet(nums,i-1,ans,subset);
                subset.pop_back();
            }
            
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        powerSet(nums,nums.size()-1,ans,subset);
        return ans;
        // set<vector<int>> ans;
        // vector<int> subset;
        // sort(nums.begin(),nums.end());
        // powerSet(nums,nums.size()-1,ans,subset);
        // vector<vector<int>> subsets(ans.begin(),ans.end());
        // return subsets;
    }
};