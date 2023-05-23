class Solution {
public:
    int mod=1e9+7;
    long long ans=0;
    bool isPal(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    void solve(string &s,int index,string &s1,string &s2){
        if(index==s.size()){
            if(isPal(s1) && isPal(s2)){
                long long val=s1.size()*s2.size();
                ans=max(ans,val%mod);
                
            }
            return ;
        }
        s1.push_back(s[index]);
        solve(s,index+1,s1,s2);
        s1.pop_back();
        s2.push_back(s[index]);
        solve(s,index+1,s1,s2);
        s2.pop_back();
        solve(s,index+1,s1,s2);
    }
    int maxProduct(string s) {
        string s1="";
        string s2="";
        solve(s,0,s1,s2);
        return ans;
    }
};