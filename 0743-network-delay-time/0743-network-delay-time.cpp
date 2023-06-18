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
        vector<int> distance(n+1,INT_MAX);
        distance[0]=INT_MIN;
        distance[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:graph[node]){
                if(dis+it[1]<distance[it[0]] ){
                    distance[it[0]]=dis+it[1];
                    pq.push({distance[it[0]],it[0]});
                }
            }
        }
        int maxTime=*max_element(distance.begin(),distance.end());
        return maxTime==INT_MAX?-1:maxTime;
    }
};