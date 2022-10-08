class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        int increasing=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])
                increasing=1;
            else {
                increasing=0;
                break;                
            }
        }
        if(increasing)
            return true;
        int decreasing=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])
                decreasing=1;
            else{
                decreasing=0;
                break;                
            }
        }
        if(decreasing)
            return true;
        return false;
    }
};