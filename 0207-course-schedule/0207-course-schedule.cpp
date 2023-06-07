class Solution {
public:
    bool detectCycle(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfs){
        visited[node]=1;
        dfs[node]=1;
        for(int it:adj[node]){
            if(!visited[it]){
                if(detectCycle(it,adj,visited,dfs))
                    return true;
            }
            else if(dfs[it])
                return true;
        }
        dfs[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
       vector<int> visited(n),dfs(n);
        for(int i=0;i<n;i++){
            if(!visited[i] && detectCycle(i,adj,visited,dfs))
                return false;
        }
        return true;
    }
};