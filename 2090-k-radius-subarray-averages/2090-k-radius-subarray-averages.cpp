class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        if(2*k>=n){
            return ans;
        }
        int mod=1e9+7;
        long long window=0;
        for(int i=0;i<=2*k;i++){
            window+=nums[i];
        }
        ans[k]=window/(2*k+1);
        int j=0;
        for(int i=k+1;i<n-k;i++){
            if(i+k>n){
                return ans;
            }
            window=window+nums[i+k]-nums[j++];
            ans[i]=window/(2*k+1);  
        }
        return ans;
        
        
        
    }
};