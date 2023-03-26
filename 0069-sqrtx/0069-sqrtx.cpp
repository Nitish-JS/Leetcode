class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        long long mid;
        int ans;
        int mod=1e9+7;
        while(low<=high){
            mid=(low+(high-low)/2)%mod;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x){
                low=mid+1;
                ans=mid;
            }
            else 
                high=mid-1;
        }
        return ans;
    }
};