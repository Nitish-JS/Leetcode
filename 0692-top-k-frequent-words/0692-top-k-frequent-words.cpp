class Solution {
public:
    struct comparator{
        bool operator()(pair<string,int> &p1,pair<string,int> &p2){
            if(p1.second!=p2.second)
                return p1.second>p2.second;
            else 
                return p1.first<p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,comparator> pq;
        for(auto it:mp){
            pq.push(it);
            if(pq.size()>k)
                pq.pop();

        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            // cout<<pq.top().first<<" "<<pq.top().second<<"\n";
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};