class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size(),mid;
        while(left<right){
            
            mid=left+(right-left)/2;
            // cout<<nums[mid]<<'\n';
            if(nums[mid]>=target)
                right=mid;
            else
                left=mid+1;
        }
        return left;
        
    }
};