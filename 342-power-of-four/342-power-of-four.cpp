class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        return fmod(log10(n)/log10(4),1)==0;
    }
};