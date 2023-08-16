class Solution {
public:
    // int solve(int index,vector<vector<int>> &envelopes,int prevW,int prevH,unordered_map<string,int> &dp){
    //     if(index<0){
    //         return 0;
    //     }
    //     string key=to_string(index)+"#"+to_string(prevW)+"#"+to_string(prevH);
    //     if(dp.find(key)!=dp.end())
    //         return dp[key];
    //     int take=INT_MIN;
    //     if(envelopes[index][0]<prevW && envelopes[index][1]<prevH){
    //         take=1+solve(index-1,envelopes,envelopes[index][0],envelopes[index][1],dp);
    //     }
    //     int nottake=0+solve(index-1,envelopes,prevW,prevH,dp);
    //     return  dp[key]=max(take,nottake);
    // }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        // unordered_map<string,int> dp;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxWidth+2,vector<int>(maxHeight+2,-1)));
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a1,vector<int> &a2){
            if(a1[0]==a2[0])
                return a1[1]>a2[1];
            return a1[0]<a2[0];
        });
        vector<int> ans;
        int size=1;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(ans.back()<envelopes[i][1]){
                ans.push_back(envelopes[i][1]);
                size++;
            }
               
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        return size;
        // return solve(n-1,envelopes,INT_MAX,INT_MAX,dp);
        
    }
};