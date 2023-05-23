class Solution {
public:
    int myAtoi(string s) {
        int mod=1e9+7;
        int i=0;
        double ans=0;
        while(s[i]==' ')
            i++;
        bool pos=s[i]=='+';
        bool neg=s[i]=='-';
        pos==true?i++:i;
        neg==true?i++:i;
        while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9){
            ans=(ans*10)+s[i++]-'0';
        }
        ans=neg?ans*-1:ans;
        if(ans<=INT_MIN) return INT_MIN;
        else if(ans>=INT_MAX) return INT_MAX;
        return (int)ans;
    }
};