class Solution {
private:
    void buildGraph(vector<vector<int>> graph[],vector<vector<int>> &flights){
        for(auto edge:flights){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph[n];
        buildGraph(graph,flights);
        vector<int> distance(n,INT_MAX);
        distance[src]=0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int stops=pq.front().first;
            int node=pq.front().second.first;
            int dis=pq.front().second.second;
            pq.pop();
            if(stops>k)
                continue;
            for(auto it:graph[node]){
                if(dis+it[1]<distance[it[0]] && stops<=k){
                    distance[it[0]]=dis+it[1];
                    pq.push({stops+1,{it[0],distance[it[0]]}});
                }
            }
        }
        
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};