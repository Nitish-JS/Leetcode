class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0,currSum=0;
        int ans=INT_MAX;
        for(right=0;right<nums.size();right++){
            currSum+=nums[right];
            while(currSum>=target){
                ans=min(ans,right-left+1);
                currSum-=nums[left];
                left++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};