class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if( nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
        }
        int maxIndex=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxIndex=i;
                maxi=dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxIndex]);
        while(maxIndex!=hash[maxIndex]){
            maxIndex=hash[maxIndex];
            ans.push_back(nums[maxIndex]);
        }
        return ans;
     
    }
};