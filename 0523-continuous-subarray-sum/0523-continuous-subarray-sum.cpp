class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<=1)
            return false;
        unordered_map<int,int> um;
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            prefix=prefix%k;
            if(prefix==0 && i>0)
                return true;
            if(um.find(prefix)!=um.end()){
                if(i-um[prefix]>1) return true;
            }
            else
                um[prefix]=i;
        }
        return false;
        
        
    }
};