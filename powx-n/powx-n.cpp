class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int m=long(abs(n));
        while(m>0){
            if(m%2==1) ans*=x;
            m/=2;
            x*=x;
        }
        return n>=0?ans:1/ans;
    }
     // long m = n > 0 ? n : -(long)n;
     //    double ans = 1.0;
     //    while (m != 0) {
     //        if (m % 2 != 0) // check if m is odd number
     //            ans *= x; // 2¹ * 2² * 2⁴, etc
     //        x *= x;
     //        m /= 2; // binary search
     //    }
     //    return n >= 0 ? ans : 1 / ans;
     // long m = n > 0 ? n : -(long)n;
     //    double ans = 1.0;
     //    while (m != 0) {
     //        if (m % 2 != 0) // check if m is odd number
     //            ans *= x; // 2¹ * 2² * 2⁴, etc
     //        x *= x;
     //        m /= 2; // binary search
     //    }
     //    return n >= 0 ? ans : 1 / ans;
};