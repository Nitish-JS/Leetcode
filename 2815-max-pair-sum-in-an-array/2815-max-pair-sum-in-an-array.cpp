class Solution {
public:
    int maxDigit(int n){
        int maxi=0;
        while(n>0){
            maxi=max(maxi,n%10);
            n/=10;
        }
        return maxi;
    }
    int maxSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int> maxdigits(n);
        for(int i=0;i<n;i++)
            maxdigits[i]=maxDigit(nums[i]);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(maxdigits[i]==maxdigits[j])
                    ans=max(nums[i]+nums[j],ans);
            }
        }
        return ans==0?-1:ans;
    }
};