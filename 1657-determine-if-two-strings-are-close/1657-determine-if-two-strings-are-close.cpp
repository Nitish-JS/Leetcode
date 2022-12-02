class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<bool> visited1(26,0);
        vector<bool> visited2(26,0);
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
            visited1[word1[i]-'a']=true;
            visited2[word2[i]-'a']=true;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if( freq1==freq2 && visited1==visited2)
            return true;
        else
            return false;
    }
};