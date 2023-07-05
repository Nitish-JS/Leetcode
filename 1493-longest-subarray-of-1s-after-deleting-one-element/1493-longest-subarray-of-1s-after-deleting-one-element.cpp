class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int longWindow=0;
        int start=0;
        for(int i=0;i<nums.size();i++){
            zero+=(nums[i]==0);
            while(zero>1){
                zero-=(nums[start]==0);
                start++;
            }
            longWindow = max(longWindow, i - start);
        }
        return longWindow;
    }
};