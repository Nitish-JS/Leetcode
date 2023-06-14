class Solution {
public:
    bool isCyclic(vector<vector<int>> &graph,vector<int> &visited,vector<int> &dfsVisited,int node){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                if(isCyclic(graph,visited,dfsVisited,it)==true)
                    return true;
            }
           else if(dfsVisited[it])
               return true;
        }
        dfsVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        int V=graph.size();
        vector<int> visited(V);
        vector<int> dfsVisited(V);
        for(int i=0;i<V;i++){
            if(isCyclic(graph,visited,dfsVisited,i)==false)
                safeNodes.push_back(i);
        }
        return safeNodes;
        
        
        
    }
};