class Solution {
public:

    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        int dp;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;
            dp=max(pick,notpick);
            prev2=prev;
            prev=dp;
        }
       return prev;
    }
};