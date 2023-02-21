class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            if(mid%2==1)
                mid--;
            if(mid+1<n && nums[mid]==nums[mid+1])
                l=mid+2;
            else{
                r=mid-1;
                ans=nums[mid];
            }
        }
        return ans;
        
    }
};