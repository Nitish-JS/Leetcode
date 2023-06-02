class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1;
        int len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
               len++;
            }
            else{
                ans=max(len,ans);
                len=1;
            }   
        }
        ans=max(len,ans);
        return ans;        
    }
};