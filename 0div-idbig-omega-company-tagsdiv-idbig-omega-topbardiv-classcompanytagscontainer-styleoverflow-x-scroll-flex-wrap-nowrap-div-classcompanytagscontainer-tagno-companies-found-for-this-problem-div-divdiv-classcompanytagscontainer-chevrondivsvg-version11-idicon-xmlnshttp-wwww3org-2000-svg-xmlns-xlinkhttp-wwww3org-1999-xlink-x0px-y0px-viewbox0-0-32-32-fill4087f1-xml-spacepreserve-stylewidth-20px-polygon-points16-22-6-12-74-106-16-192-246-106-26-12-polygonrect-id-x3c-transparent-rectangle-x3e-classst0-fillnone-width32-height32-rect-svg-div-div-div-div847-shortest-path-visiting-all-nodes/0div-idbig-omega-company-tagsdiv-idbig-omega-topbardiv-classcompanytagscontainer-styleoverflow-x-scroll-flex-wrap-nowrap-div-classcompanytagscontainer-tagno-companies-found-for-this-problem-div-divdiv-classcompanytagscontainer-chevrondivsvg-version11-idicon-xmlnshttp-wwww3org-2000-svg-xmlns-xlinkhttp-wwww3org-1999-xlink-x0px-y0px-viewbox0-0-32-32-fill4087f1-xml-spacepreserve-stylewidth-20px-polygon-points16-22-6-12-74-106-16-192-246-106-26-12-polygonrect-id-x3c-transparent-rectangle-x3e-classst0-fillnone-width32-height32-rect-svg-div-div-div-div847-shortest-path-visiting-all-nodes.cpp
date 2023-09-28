class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1<<n) - 1;
        queue<pair<int,pair<int,int>>> q;

        vector<vector<bool>> visited(mask + 1, vector<bool>(n, false));

        for (int node = 0; node < n; ++node) {
            int origMask = (1 << node);
            q.push({node, {origMask, 1}});
            visited[origMask][node] = true;
        }

        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int currNode = curr.first;
            int currMask = curr.second.first;
            int currLength = curr.second.second;

            if (currMask == mask)
                return currLength - 1;

            for (int i = 0; i < graph[currNode].size(); ++i) {
                int neighbor = graph[currNode][i];
                int newMask = currMask | (1 << neighbor);

                if (visited[newMask][neighbor])
                    continue;

                q.push({neighbor, {newMask, currLength + 1}});
                visited[newMask][neighbor] = true;
            }
        }
        return -1;  
    }
};
