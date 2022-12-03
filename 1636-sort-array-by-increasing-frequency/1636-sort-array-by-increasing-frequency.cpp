class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>> intFreqPair;
        for(auto it:mp){
            intFreqPair.push_back(it);
        }
        sort(intFreqPair.begin(),intFreqPair.end(),[](auto &a,auto &b){
            return a.second<b.second || (a.second==b.second && a.first>b.first);
        });
        vector<int> ans;
        for(auto it:intFreqPair){
            ans.insert(ans.end(),it.second,it.first);
        }
        return ans;
    }
};