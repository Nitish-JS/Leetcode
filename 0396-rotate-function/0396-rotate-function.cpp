class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=0;
        int sum=0;
        for(int i=0;i<n;i++){
            prev+=nums[i]*i;
            sum+=nums[i];
        }
        int ans=prev;
        for(int i=1;i<n;i++){
            curr=prev+sum-n*nums[n-i];
            ans=max(ans,curr);
            prev=curr;
        }
        return ans;
    }
};