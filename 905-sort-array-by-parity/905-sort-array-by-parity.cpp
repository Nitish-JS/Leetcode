class Solution {
public:     
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[j]%2==1){
                j--;
                continue;
            }
                // j--;
            if(nums[i]%2==1){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j--;
            }
            i++;
        }
        return nums;
    }
};