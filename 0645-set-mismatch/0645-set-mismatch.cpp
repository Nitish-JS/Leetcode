class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       unordered_map<int,int> um;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
            if(um[nums[i]]>1){
                ans.push_back(nums[i]);
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(um[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};