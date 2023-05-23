class Solution {
public:
    string longestPalindrome(string s) {
         int n=s.size();
        if(n==0)
             return "";
        vector<vector<int>> dp(n,vector<int>(n,0));
        int len=1;
        int start=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        // 
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        if(j-i+1>len){
                            start=i;
                            len=j-i+1;
                        }

                    }
                }
            }
        }
        return s.substr(start,len);
    }
};