class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long m=long(abs(n));
        while(m>0){
            if(m%2==1) ans*=x;
            m/=2;
            x*=x;
        }
        return n>=0?ans:1/ans;
    }
};
     