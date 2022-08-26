class Solution {
public:
    bool isPowerOfTwo(int n) {
       // return n>0 && (int)pow(2,30)%n==0;
        return n>0 && 1073741824%n==0;
    }
};