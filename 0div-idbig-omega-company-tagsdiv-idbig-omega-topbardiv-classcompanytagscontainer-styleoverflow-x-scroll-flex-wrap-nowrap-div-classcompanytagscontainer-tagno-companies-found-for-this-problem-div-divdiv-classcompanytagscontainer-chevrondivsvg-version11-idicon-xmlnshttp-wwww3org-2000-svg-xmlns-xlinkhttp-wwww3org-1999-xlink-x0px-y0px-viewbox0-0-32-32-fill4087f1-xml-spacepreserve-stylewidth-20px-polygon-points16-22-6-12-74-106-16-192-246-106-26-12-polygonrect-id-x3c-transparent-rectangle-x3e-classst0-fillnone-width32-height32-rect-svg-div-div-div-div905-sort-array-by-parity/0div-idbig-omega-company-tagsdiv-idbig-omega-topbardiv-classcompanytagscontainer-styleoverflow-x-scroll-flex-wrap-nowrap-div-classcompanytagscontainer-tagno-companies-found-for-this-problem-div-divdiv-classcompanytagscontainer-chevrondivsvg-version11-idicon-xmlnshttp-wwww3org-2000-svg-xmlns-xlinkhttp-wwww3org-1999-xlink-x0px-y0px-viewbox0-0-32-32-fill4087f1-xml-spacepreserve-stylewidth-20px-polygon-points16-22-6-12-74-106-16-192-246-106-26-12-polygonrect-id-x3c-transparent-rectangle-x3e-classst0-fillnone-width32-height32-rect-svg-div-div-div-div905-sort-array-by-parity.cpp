class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[j]&1){
                j--;
                continue;
            }
            if(nums[i]&1){
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }
        return nums;
    }
};