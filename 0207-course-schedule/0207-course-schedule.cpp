class Solution {
public:
    void buildGraph(vector<int> adj[],vector<vector<int>> &prereq){
        for(auto edge:prereq){
            adj[edge[1]].push_back(edge[0]);
        }
    }
    bool detectCycleDfs(vector<int> adj[],int node,vector<int> &visited,vector<int> &dfsVisited){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(detectCycleDfs(adj,it,visited,dfsVisited)==true)
                    return true;
            }
            else if(dfsVisited[it])
                return true;
        }
        dfsVisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        buildGraph(adj,prerequisites);
        vector<int> visited(numCourses);
        vector<int> dfsVisited(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(detectCycleDfs(adj,i,visited,dfsVisited)==true)
                    return false;
            }
        }
        return true;
    }
};