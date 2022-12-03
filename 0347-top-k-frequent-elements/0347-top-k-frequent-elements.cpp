class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>> freqPair;
        for(auto it:mp){
            freqPair.push_back(it);
        }
        sort(freqPair.begin(),freqPair.end(),[&](auto a,auto b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freqPair[i].first);
        }
        return ans;
    }
};