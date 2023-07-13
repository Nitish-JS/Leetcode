class Solution {
public:
    bool isCycle(vector<vector<int>> &graph,vector<int> &visited,vector<int> &dfsVisited,int node){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                if(isCycle(graph,visited,dfsVisited,it))
                    return true;
            }
            else if(dfsVisited[it])
                return true;
        }
        dfsVisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> graph(V);
        for(auto edge:prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }        
        vector<int> visited(V);
        vector<int> dfsVisited(V);
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycle(graph,visited,dfsVisited,i))
                return false;
        }
        return true;
        
    }
};