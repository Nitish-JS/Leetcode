class Solution {
public:
    string reverseVowels(string s) {
        string temp="";
        for(auto i:s){
            if(i=='a' || i=='e' || i=='o' || i=='i' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U')
                temp+=i;
        }
        reverse(temp.begin(),temp.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                s[i]=temp[j++];
        }
        return s;
    }
};