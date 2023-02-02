class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            if(!isSorted(words[i],words[i+1],mp)) return false;
        }
        return true;
        
    }
    bool isSorted(string &a,string &b,map<char,int> &mp){
        int i=0;
        while(i<a.size() && i<b.size()){
            if(mp[a[i]]!=mp[b[i]]) return mp[a[i]]<mp[b[i]];
            i++;
        }
        return a.size()<=b.size();
    }
};