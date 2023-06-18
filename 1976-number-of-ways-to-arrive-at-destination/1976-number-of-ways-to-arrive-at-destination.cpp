class Solution {
private:
    void buildGraph(vector<vector<long long>> graph[],vector<vector<int>>&roads){
        for(auto edge:roads){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> graph[n];
        buildGraph(graph,roads);
        vector<long long> distance(n,LONG_MAX);
        vector<long long> count(n,0);
        count[0]=1;
        int ans=0;
        int mod=1e9+7;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        distance[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:graph[node]){
                if(dis+it[1]<distance[it[0]]){
                    count[it[0]]=count[node];
                    distance[it[0]]=(dis+it[1]);
                    pq.push({dis+it[1],it[0]});
                }
                else if(dis+it[1]==distance[it[0]]){
                    count[it[0]]=(count[it[0]]+count[node])%mod;
                }
            }
        }
        return count[n-1]%mod;
    }
};