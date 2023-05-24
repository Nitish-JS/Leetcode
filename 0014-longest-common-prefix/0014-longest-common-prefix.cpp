class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length=INT_MAX;
        for(auto s:strs){
            length=min(length,(int)s.size());
        }
        sort(strs.begin(),strs.end());
        string first=strs[0],last=strs[strs.size()-1];
        int i=0;
        string ans="";
        while(i<length && first[i]==last[i])
            ans+=first[i++];
        return ans;
        
    }
};