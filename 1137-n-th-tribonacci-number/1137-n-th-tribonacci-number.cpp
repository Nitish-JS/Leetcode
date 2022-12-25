class Solution {
public:
    int tribonacci(int n) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        int trib1=0;
        int trib2=1;
        int trib3=1;
        int ans;
        for(int i=3;i<=n;i++){
            ans=trib1+trib2+trib3;
            trib1=trib2;
            trib2=trib3;
            trib3=ans;
        }
        return ans;
    }
};