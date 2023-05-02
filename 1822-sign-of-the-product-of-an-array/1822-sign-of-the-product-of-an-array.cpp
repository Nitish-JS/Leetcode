class Solution {
public:
    int arraySign(vector<int>& nums) {
        int mod=1e9+7;
        long prod=1;
        for(int i:nums){
            prod=(prod*i)%mod;
        }
        return prod==0?0:prod<0?-1:1;
    }
};