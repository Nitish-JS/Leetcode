class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> um;
        int maxFreq=0;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
            maxFreq=max(um[nums[i]],maxFreq);
        }
        vector<vector<int>> ans(maxFreq);
        for(auto it:um){
            int num=it.first;
            int count=it.second;
            for(int i=0;i<count;i++){
                ans[i].push_back(num);
            }
        }
        return ans;
     
    }
};