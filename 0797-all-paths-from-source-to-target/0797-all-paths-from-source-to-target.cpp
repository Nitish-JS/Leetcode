class Solution {
vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>> &graph,vector<int> temp,int node,int n){
        temp.push_back(node);
        if(node==n){
            ans.push_back(temp);
            return;
        }
        for(auto it:graph[node]){
           dfs(graph,temp,it,n);
        }      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()-1;
        vector<int> visited(n+1,0);
        vector<int> temp;
        dfs(graph,temp,0,n);
        return ans;
    }
};