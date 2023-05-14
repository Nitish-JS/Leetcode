class Solution {
public:
void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj_list, int& vertices, int& edges) {
    visited[u] = true;
    vertices++;
    edges += adj_list[u].size();
    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, visited, adj_list, vertices, edges);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int u = 0; u < n; u++) {
            if (!visited[u]) {
                int vertices = 0, edges = 0;
                dfs(u, visited, adj_list, vertices, edges);
                edges /= 2;
                if (edges == vertices * (vertices - 1) / 2) {
                    count++;
                }
            }
        }
        return count;
    }
};