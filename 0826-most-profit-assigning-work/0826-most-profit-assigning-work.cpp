class Solution {
public:
   
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<difficulty.size();i++){
            pq.push({profit[i],difficulty[i]});
        }
        int ans=0;
        sort(worker.begin(),worker.end(),greater<int>());
        for(int capacity:worker){
            while(!pq.empty()){
                if(pq.top().second>capacity){
                    pq.pop();
                }
                else{
                    ans+=pq.top().first;
                    break;
                }
            }
            if(pq.empty())
                break;
        }
        return ans;
    }
};