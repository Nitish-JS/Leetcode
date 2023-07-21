class Solution {
public:
    bool check(string &a,string &b){
        if(a.size()!=b.size()+1)
            return false;
        int i=0,j=0;
        while(i<a.size()){
            if(j<b.size() && a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==a.size() && j==b.size())
            return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size()<s2.size();
        });
        // for(auto it:words)
        //     cout<<it<<" ";
        // cout<<'\n';
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // cout<<words[i]<<" "<<words[j]<<" "<<check(words[i],words[j])<<"\n";
                if(dp[j]+1>dp[i] && check(words[i],words[j]))
                    dp[i]=dp[j]+1;
            }
            ans=max(ans,dp[i]);
            
        }
        return ans;
       
        return 0;
    }
};