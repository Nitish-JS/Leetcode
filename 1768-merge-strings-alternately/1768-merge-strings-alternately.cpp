class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n=word1.size();
        int m=word2.size();
        string ans="";
        int iter=0;
        while(i<n && j<m){
            if(iter%2==0){
                ans+=word1[i++];
                iter++;
            }
            else{
                ans+=word2[j++];
                iter++;
            }
        }
        if(i<n){
            ans+=word1.substr(i);
        }
        if(j<m)
            ans+=word2.substr(j);
        return ans;
        
    }
};