class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left=0,right=nums.size()-1;
        for(int k=right;k>=0;k--){
            if(abs(nums[right])>abs(nums[left])) result[k]=nums[right]*nums[right--];
            else result[k]=nums[left]*nums[left++];
        }
        return result;
    }
};