class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        int digitA,digitB;
        int carry=0;
        string res="";
        while(i>=0 || j>=0){
            if(i>=0) digitA=(int)a[i]-'0';
            else digitA=0;
            if(j>=0) digitB=(int)b[j]-'0';
            else digitB=0;
            int total=digitA+digitB+carry;
            res=to_string(total%2)+res;
            carry=total/2;
            i--;
            j--;
        }
        return carry==1?to_string(carry)+res:res;
    }
};