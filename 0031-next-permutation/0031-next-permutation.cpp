class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakpoint=i;
                break;
            }
        }
        if(breakpoint==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[i],nums[breakpoint]);
                break;
            }
        }
        sort(nums.begin()+breakpoint+1,nums.end());
    }
};