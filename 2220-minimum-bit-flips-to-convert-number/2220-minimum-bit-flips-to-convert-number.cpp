class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorSum=start^goal;
        int count=0;
        while(xorSum){
            xorSum=xorSum&(xorSum-1);
            count++;
        }
        return count;
    }
};