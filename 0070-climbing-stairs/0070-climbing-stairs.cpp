class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)
            return 1;
        int step1=1,step2=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=step1+step2;
            step1=step2;
            step2=ans;
        }
        return ans;
    }
};