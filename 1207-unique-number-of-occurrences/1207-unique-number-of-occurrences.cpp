class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(int i:arr){
            mp[i]++;
        }
        set<int> s;
        arr.clear();
        int i=0;
        for(auto it:mp){
            s.insert(it.second);
            arr.push_back(it.second);
        }
        for(auto i:s){
            cout<<i<<" ";
        }
        cout<<'\n';
        for(auto i:arr){
            cout<<i<<" ";
        }
        if(s.size()==arr.size())
            return true;
        else
            return false;
        
    }
};