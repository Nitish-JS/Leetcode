class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        map<int,int> m1;
        map<int,int> m2;
        for(int i=0;i<word1.size();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        vector<int> freq1;
        vector<int> freq2;
        for(auto it:m1){
            if(m2.find(it.first)==m2.end())
                return false;
            freq1.push_back(it.second);
        }
         for(auto it:m2){
            freq2.push_back(it.second);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if(freq1==freq2)
            return true;
        else
            return false;
    }
};