class Solution {
private:
    void buildGraph(vector<vector<int>> graph[],vector<vector<int>> &times){
        for(auto edge:times){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }
        
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph[n+1];
        buildGraph(graph,times);
        vector<int> distance(n+1,-1);
        distance[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(auto it:graph[node]){
                if(it[1]+distance[node]<distance[it[0]] || distance[it[0]]==-1){
                    distance[it[0]]=it[1]+distance[node];
                    pq.push({distance[it[0]],it[0]});
                }
            }
        }
        int maxTime=0;
        for(int i=1;i<=n;i++){
            maxTime=max(distance[i],maxTime);
            if(distance[i]==-1)
                return -1;
        }
        return maxTime;
    }
};