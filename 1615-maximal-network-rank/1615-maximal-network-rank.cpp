class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<int> adj[n];
        vector<int> degree(n,0);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if(i!=j){
                    int rank=0;
                    if(adj[i].find(j)!=adj[i].end())
                        rank=degree[i]+degree[j]-1;
                    else
                        rank=degree[i]+degree[j];
                    ans=max(rank,ans);
                // }
            }
        }
        return ans;
    }
};