class Solution {
public:
    int vowelCount(string s){
        int ans=0;
        for(auto i:s){
            if(i=='a' || i=='e' || i=='o' || i=='u' || i=='i' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U')
                ans++;
        }
        return ans;
    }
    bool halvesAreAlike(string s) {
        string a=s.substr(0,s.size()/2);
        string b=s.substr(s.size()/2);
        cout<<a<<" "<<b;
        return vowelCount(a)==vowelCount(b)?true:false;
    }
};