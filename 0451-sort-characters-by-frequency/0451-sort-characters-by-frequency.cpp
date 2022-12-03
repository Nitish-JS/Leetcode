class Solution {
public:
    static bool CompareFrequency(pair<char,int> &a,pair<char,int> &b){
        return b.second<a.second;
    }
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> freqPair;
        for(auto it:mp){
            freqPair.push_back(it);
        }
        sort(freqPair.begin(),freqPair.end(),CompareFrequency);
        string ans;
        for(auto it:freqPair){
            
           ans.append(it.second,it.first);
            cout<<it.first<<" "<<it.second<<"\n";
        }
        return ans;
    }
};