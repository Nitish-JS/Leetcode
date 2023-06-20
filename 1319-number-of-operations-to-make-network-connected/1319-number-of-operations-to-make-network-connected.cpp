class Solution {
private:
    void buildGraph(vector<int> adj[],vector<vector<int>> &connections){
        for(auto edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }
//     DFS Approach
    void dfs(vector<int> adj[],vector<int> &visited,int node){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
        }
    }
//     BFS Approach gives TLE
    void bfs(vector<int> adj[],vector<int> &visited,int node){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            visited[currNode]=1;
            for(auto it:adj[currNode]){
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int> adj[n];
        buildGraph(adj,connections);
        int connectedComponents=0;
        vector<int> visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                connectedComponents++;
                dfs(adj,visited,i);
//              bfs(adj,visited,i); TLE 
//              TRY UNION FIND
            }
        }
        return connectedComponents-1;
    }
};