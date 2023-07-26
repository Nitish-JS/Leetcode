class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    if(nums[k]-nums[j]==diff && nums[j]-nums[i]==diff)
                        ans++;
                }
            }
        }
        return ans;
    }
};