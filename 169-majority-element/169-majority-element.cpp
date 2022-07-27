class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto it:um){
            if(it.second>nums.size()/2)
                return it.first;
        }
        return 0;
    }
};