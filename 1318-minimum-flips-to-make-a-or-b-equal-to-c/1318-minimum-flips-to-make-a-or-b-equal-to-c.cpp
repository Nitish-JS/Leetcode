class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            int cLSB=c&1;
            int aLSB=a&1;
            int bLSB=b&1;
            if(cLSB==1){
                if((aLSB | bLSB)==0)
                    ans++;
            }
            else{
                if(aLSB | bLSB)
                    ans+=(aLSB&1)+(bLSB&1);
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
    
};