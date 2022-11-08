class Solution {
public:
    string makeGood(string s) {
        if(s.size()==0)
            return s;
        string ans="";
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(abs((int)s[i]-(int)(s[i+1]))==32){
                s=s.substr(0,i)+s.substr(i+2);
                i=-1;
                n-=2;
            }
        }
        return s;
    }
};