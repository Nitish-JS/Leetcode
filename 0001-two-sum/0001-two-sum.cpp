class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            if(um.find(target-nums[i])!=um.end())
                return {i,um[target-nums[i]]};
            else
                um[nums[i]]=i;
        }
        return {0,0};
    }
};