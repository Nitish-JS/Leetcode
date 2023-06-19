class Solution {
private:
    void buildGraph(vector<pair<int,double>> graph[],vector<vector<int>> &edges,vector<double> &succProb){
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
        vector<pair<int,double>> graph[n];
        buildGraph(graph,edges,succProb);
        vector<double> probArr(n,0.0);
        probArr[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1.00,start});
        while(!pq.empty()){
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:graph[node]){
                int adjNode=it.first;
                double adjProb=it.second;
                if(prob*adjProb > probArr[adjNode]){
                    probArr[adjNode]=prob*adjProb;
                    pq.push({prob*adjProb,adjNode});
                }
            }
        }
        return probArr[end];
        
    }
};