class Solution {
public:
//     void dfs(int node,vector<int> graph[],vector<int> &visited,vector<int> &path){
//         int visited[node]=1;
//         path.push_back(node);
//         for(auto it:graph[node]){
//             if(!visited[it])
//                 dfs(it,graph,visited,path);
//         }
        
//     }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // vector<int> graph[n];
        vector<int> inDegree(n,0);
        for(int i=0;i<edges.size();i++){
            // graph[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                ans.push_back(i);
        }
        return ans;
        // priority_queue<pair<int,int>> pq;
        // for(int i=0;i<n;i++){
        //     vector<int> visited(n,0);
        //     vector<int> path;
        //     dfs(i,graph,visited,path);
        //     pq.push_back({path.size(),})
        // }
        
    }
};