class Solution {
public:
    // dfs approach
    // bool detectCycle(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfs){
    //     visited[node]=1;
    //     dfs[node]=1;
    //     for(int it:adj[node]){
    //         if(!visited[it]){
    //             if(detectCycle(it,adj,visited,dfs))
    //                 return true;
    //         }
    //         else if(dfs[it])
    //             return true;
    //     }
    //     dfs[node]=0;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     int n=numCourses;
    //     vector<int> adj[n];
    //     for(auto edge:prerequisites){
    //         adj[edge[1]].push_back(edge[0]);
    //     }
    //    vector<int> visited(n),dfs(n);
    //     for(int i=0;i<n;i++){
    //         if(!visited[i] && detectCycle(i,adj,visited,dfs))
    //             return false;
    //     }
    //     return true;
    // }
    
    // bfs approach
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(int it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return count==V?true:false;
    }
    
};