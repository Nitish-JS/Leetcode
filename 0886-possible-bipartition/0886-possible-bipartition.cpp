class Solution {
public:
    bool bipartiteDfs(int node,vector<vector<int>> &graph,int color[]){
        if (color[node]==-1)
            color[node]=1;
        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!bipartiteDfs(it,graph,color))
                    return false;
            }
            else if(color[it]==color[node])
                    return false;
        }
        return true;
    }
    bool checkBipartite(vector<vector<int>> &graph,int n){
       int color[n];
       memset(color,-1,sizeof(color));
       for(int i=0;i<n;i++){
           if(color[i]==-1){
                if(!bipartiteDfs(i,graph,color))
                    return false;
           }
       }
       return true;
   }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
           
        }
        return checkBipartite(graph,n+1);

    }
};