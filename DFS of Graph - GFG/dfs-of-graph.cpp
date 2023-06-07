//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<int> adj[],vector<int> &visited,vector<int> &dfsPath,int index){
        dfsPath.push_back(index);
        visited[index]=1;
        for(auto it:adj[index]){
            if(!visited[it])
                dfs(adj,visited,dfsPath,it);
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V);
        vector<int> dfsPath;
        for(int i=0;i<V;i++){
            //if a node is not visited then perform traversal from that node.
            if(!visited[i]){
                dfs(adj,visited,dfsPath,i);
            }
        }
        return dfsPath;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends