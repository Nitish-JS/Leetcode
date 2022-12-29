class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        vector<int> ans;
        int n=tasks.size();
        long time=0,curr=0;
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        while(curr<n || !pq.empty()){
            if(pq.empty()){
                time=max(time,(long)tasks[curr][0]);
            }
            while(curr<n && time>=tasks[curr][0]){
                pq.push({tasks[curr][1],tasks[curr][2]});
                curr++;
            }
            auto it=pq.top();
            pq.pop();
            time+=it.first;
            ans.push_back(it.second);
            
        }
        return ans;
    }
};