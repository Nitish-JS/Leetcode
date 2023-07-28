//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// 	void topoSortDfs(int node,vector<int> adj[],stack<int> &topo,vector<int> &visited){
// 	    visited[node]=1;
// 	    for(auto it:adj[node]){
// 	        if(!visited[it]){
// 	            topoSortDfs(it,adj,topo,visited);
// 	        }
// 	    }
// 	    topo.push(node);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int> topo;
// 	    vector<int> visited(V);
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i])
// 	            topoSortDfs(i,adj,topo,visited);
// 	    }
// 	    vector<int> ans;
// 	    while(!topo.empty()){
// 	        ans.push_back(topo.top());
// 	        topo.pop();
// 	    }
// 	    return ans;
// 	    // code here
// 	}
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V);
        // vector<int> visited(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                topo.push_back(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    topo.push_back(it);
                }
            }
        }
        return topo;
        // code here
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends