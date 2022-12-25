class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size());
        sort(nums.begin(),nums.end());
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=upper_bound(prefix.begin(),prefix.end(),queries[i])-prefix.begin();
        }
        return ans;
    }
};