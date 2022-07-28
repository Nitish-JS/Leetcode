class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_first=INT_MIN,max_second=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_first){
                max_second=max_first;
                max_first=nums[i];
            }
            else if(nums[i]>max_second){
                max_second=nums[i];
            }
        }
        return (max_first-1)*(max_second-1);
    }
};