class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        long long mid;
        int mod=1e9+7;
        int ans;
        while(low<=high){
            mid=(low+(high-low)/2)%mod;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};