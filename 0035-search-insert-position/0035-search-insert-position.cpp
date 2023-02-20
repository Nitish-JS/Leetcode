class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        int mid;
        while(left<right){
             mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid;
            }
           
        }
        return left;
        
    }
};