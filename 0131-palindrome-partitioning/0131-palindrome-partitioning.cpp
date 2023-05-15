class Solution {
public:
    void solve(vector<vector<string>> &ans,vector<string> &substrings,string s,int index){
        if(index==s.size()){
            ans.push_back(substrings);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(checkPal(s,index,i)){
                substrings.push_back(s.substr(index,i-index+1));
                solve(ans,substrings,s,i+1);
                substrings.pop_back();
            }
           
        }
    }
    bool checkPal(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        solve(ans,substrings,s,0);
        return ans;
    }
};