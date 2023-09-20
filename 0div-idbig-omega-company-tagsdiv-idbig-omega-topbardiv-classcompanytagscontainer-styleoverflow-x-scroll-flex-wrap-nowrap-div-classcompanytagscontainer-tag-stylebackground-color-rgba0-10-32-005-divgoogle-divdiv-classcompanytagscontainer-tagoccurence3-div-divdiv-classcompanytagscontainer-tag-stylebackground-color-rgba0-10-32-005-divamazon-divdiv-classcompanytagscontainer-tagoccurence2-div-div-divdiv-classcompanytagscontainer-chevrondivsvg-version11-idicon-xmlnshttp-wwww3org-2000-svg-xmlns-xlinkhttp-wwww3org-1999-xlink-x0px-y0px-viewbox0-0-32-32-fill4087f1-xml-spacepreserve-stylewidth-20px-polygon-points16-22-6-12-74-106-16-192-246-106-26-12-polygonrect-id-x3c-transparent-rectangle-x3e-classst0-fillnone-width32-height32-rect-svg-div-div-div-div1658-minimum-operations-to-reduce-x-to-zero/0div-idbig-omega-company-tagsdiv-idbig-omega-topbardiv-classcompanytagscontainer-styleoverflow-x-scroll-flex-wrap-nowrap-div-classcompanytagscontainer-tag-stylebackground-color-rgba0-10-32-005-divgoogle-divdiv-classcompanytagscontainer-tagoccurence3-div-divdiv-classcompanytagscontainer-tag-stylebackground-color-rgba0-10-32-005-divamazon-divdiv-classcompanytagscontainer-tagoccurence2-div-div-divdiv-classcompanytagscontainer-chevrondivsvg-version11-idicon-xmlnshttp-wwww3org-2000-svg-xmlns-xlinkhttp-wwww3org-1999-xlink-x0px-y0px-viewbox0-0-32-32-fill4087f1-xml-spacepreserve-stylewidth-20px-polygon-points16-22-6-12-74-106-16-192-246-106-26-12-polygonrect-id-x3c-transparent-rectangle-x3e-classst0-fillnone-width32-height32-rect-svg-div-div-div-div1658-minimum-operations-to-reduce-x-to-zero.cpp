class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i:nums)
            total+=i;
        int target=total-x;
        int currSum=0;
        int left=0;
        int n=nums.size();
        int ans=-1;
        for(int right=0;right<n;right++){
            currSum+=nums[right];
            while(left<=right && currSum>target){
                currSum-=nums[left++];
            }
            if(currSum==target){
                ans=max(ans,right-left+1);
            }
        }
        return ans==-1?-1:n-ans;
    }
};