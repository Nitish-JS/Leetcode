class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='6'){
                flag=1;
                s[i]='9';
                break;
            }
        }
        if(flag==0)
            return num;
        return stoi(s);
    }
};