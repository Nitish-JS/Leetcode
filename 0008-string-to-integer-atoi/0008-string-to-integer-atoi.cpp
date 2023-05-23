class Solution {
public:
    int myAtoi(string s) {
        int mod=1e9+7;
        int i=0;
        long ans=0;
        while(s[i]==' ')
            i++;
        bool pos=s[i]=='+';
        bool neg=s[i]=='-';
        pos==true?i++:i;
        neg==true?i++:i;
        while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9){
            
            ans=(ans*10)+s[i++]-'0';
            if(ans>INT_MAX){
                if(neg)
                    return INT_MIN;
                else 
                    return INT_MAX;
                
            }
        }
        ans=neg?ans*-1:ans;
        return (int)ans;
    }
};