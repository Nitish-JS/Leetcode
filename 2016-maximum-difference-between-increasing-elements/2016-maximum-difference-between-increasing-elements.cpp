class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimum=INT_MAX;
        int max_diff=-1;
        for(int i=0;i<nums.size();i++){
            minimum=min(nums[i],minimum);
            max_diff=max(max_diff,nums[i]-minimum);
        }
        return max_diff==0?-1:max_diff;
        
    }
};