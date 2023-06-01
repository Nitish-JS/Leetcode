class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        if(nums[low]<nums[high])
            return nums[low];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])
                low=mid+1;
            else
                high=mid-1;
            if(mid-1>=0 && nums[mid]<nums[mid-1])
                return nums[mid];
            else if(mid+1<nums.size() && nums[mid]>nums[mid+1])
                return nums[mid+1];
        }
        return nums[low];
    }
};