class Solution {
public:
    int solve(int index,vector<int> &sum_array,vector<int> &dp){
        if(index<0)
            return 0;
        if(index==0)
            return sum_array[0];
        if(dp[index]!=-1)
            return dp[index];
        int take=sum_array[index]+solve(index-2,sum_array,dp);
        int nottake=0+solve(index-1,sum_array,dp);
        return dp[index]=max(take,nottake);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        int answer=INT_MIN;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> sum_array(maxi+1,0);
        vector<int> dp(maxi+1,0);
        for(int i:nums){
            sum_array[i]+=i;
        }
        dp[0]=0;
        dp[1]=sum_array[1];
        for(int index=2;index<maxi+1;index++){
            int take=sum_array[index]+dp[index-2];
            int nottake=0+dp[index-1];
            dp[index]=max(take,nottake);
        }
        return dp[maxi];
        // return solve(maxi,sum_array,dp);
        
        
    }
};