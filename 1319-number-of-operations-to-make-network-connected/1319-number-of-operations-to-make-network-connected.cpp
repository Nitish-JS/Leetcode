class DisjointSet{
    
public:
    vector<int> parent,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int u,int v){
        int ulti_parent_u=find(u);
        int ulti_parent_v=find(v);
        // both are in same component
        if(ulti_parent_u==ulti_parent_v)
            return;
        if(rank[ulti_parent_u]<rank[ulti_parent_v]){
            parent[ulti_parent_u]=ulti_parent_v;
        }
        else if(rank[ulti_parent_u]>rank[ulti_parent_v]){
            parent[ulti_parent_v]=ulti_parent_u;
        }
        else{
            parent[ulti_parent_v]=ulti_parent_u;
            rank[ulti_parent_u]++;
        }
    }
    
};

class Solution {
private:
//     void buildGraph(vector<int> adj[],vector<vector<int>> &connections){
//         for(auto edge:connections){
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//     }
//      DFS Approach
//     void dfs(vector<int> adj[],vector<int> &visited,int node){
//         visited[node]=1;
//         for(auto it:adj[node]){
//             if(!visited[it]){
//                 dfs(adj,visited,it);
//             }
//         }
//     }
//     BFS Approach gives TLE
//     void bfs(vector<int> adj[],vector<int> &visited,int node){
//         queue<int> q;
//         q.push(node);
//         while(!q.empty()){
//             int currNode=q.front();
//             q.pop();
//             visited[currNode]=1;
//             for(auto it:adj[currNode]){
//                 if(!visited[it]){
//                     q.push(it);
//                 }
//             }
//         }
//     }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
             return -1;
//         Disjoint set approach
        DisjointSet DS(n);
        for(auto it:connections){
            DS.Union(it[0],it[1]);
        }
        int connectedComponents=0;
        for(int i=0;i<n;i++){
            if(DS.parent[i]==i)
                connectedComponents++;
        }
        return connectedComponents-1;
//         DFS approach

//         vector<int> adj[n];
//         buildGraph(adj,connections);
//         int connectedComponents=0;
//         vector<int> visited(n);
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 connectedComponents++;
//                 dfs(adj,visited,i);
// //              bfs(adj,visited,i); TLE 
// //              TRY UNION FIND
//             }
//         }
//         return connectedComponents-1;
    }
};