class Solution {
public:
    int solve(vector<int> &nums,int start,int end){
        int prev=nums[start];
        int prev2=0;
        int dp;
        for(int i=start+1;i<end;i++){
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int notpick=0+prev;
            dp=max(pick,notpick);
            prev2=prev;
            prev=dp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int removefirst=solve(nums,1,nums.size());
        int removelast=solve(nums,0,nums.size()-1);
        return max(removefirst,removelast);
        
    }
};