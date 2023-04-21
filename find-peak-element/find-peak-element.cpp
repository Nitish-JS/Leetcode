class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int prev=INT_MIN;
            int next=INT_MIN;
            if(mid-1>=0 )
                prev=nums[mid-1];
            if(mid+1<n){
                next=nums[mid+1];
            }
            if(nums[mid]>prev && nums[mid]>next)
                return mid;
            if(next>nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};