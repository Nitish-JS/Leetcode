class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long temp=(long)n;
        if(n<0) temp=(long)-1*n;
        while(temp>0){
            if(temp%2){
                ans=ans*x;
                temp=temp-1;
            }
            else{
                x=x*x;
                temp/=2;
            }
        }
        return n>0?(double)ans:(double)1.0/ans;
    }
};