class Solution {
public:
    bool solve(string &s,int index,unordered_set<string> &st,vector<int> &dp){
        if(index>=s.size())
            return true;
        if(dp[index]!=-1)
            return dp[index];
        if(st.find(s)!=st.end())
            return true;
        for(int i=1;i<=s.size();i++){
            string temp=s.substr(index,i);
            if(st.find(temp)!=st.end() && solve(s,index+i,st,dp))
                return dp[index]=true;
        }
        return dp[index]=false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size(),-1);
        for(string str:wordDict)
            st.insert(str);
        return solve(s,0,st,dp);
    }
};