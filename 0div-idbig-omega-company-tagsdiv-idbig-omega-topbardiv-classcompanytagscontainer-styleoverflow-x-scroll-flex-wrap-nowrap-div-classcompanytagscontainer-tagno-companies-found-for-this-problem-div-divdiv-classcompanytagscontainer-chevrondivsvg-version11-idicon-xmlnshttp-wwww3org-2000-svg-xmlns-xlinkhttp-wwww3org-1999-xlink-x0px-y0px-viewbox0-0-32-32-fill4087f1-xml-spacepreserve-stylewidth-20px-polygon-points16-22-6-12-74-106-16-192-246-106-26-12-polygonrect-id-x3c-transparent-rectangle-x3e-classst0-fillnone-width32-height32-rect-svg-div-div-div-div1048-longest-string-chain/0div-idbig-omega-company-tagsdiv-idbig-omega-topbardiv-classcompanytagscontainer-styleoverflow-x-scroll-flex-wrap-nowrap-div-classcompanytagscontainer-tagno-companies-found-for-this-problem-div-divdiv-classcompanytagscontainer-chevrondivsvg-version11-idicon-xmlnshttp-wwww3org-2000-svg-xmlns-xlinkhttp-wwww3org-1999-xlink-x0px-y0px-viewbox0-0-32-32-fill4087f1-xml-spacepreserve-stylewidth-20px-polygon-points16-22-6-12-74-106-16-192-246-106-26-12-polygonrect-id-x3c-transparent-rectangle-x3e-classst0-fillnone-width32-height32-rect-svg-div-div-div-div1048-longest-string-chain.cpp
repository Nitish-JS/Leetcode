class Solution {
public:
    bool check(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int i=0,j=0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size())
            return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size()<s2.size();
        });
        int n=words.size();
        int ans=0;
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                 // cout<<words[i]<<" "<<words[j]<<" "<<check(words[i],words[j])<<"\n";
                if(dp[j]+1>dp[i] && check(words[i],words[j]))
                    dp[i]=dp[j]+1;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};