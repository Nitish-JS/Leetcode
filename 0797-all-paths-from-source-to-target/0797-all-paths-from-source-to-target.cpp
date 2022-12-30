class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<vector<int>> &ans,vector<int> &visited,int node){
        visited.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(visited);
        }
        else{
            for(auto edge:graph[node]){
                dfs(graph,ans,visited,edge);
            }
        }
        visited.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visited;
        vector<vector<int>> ans;
        dfs(graph,ans,visited,0);
        return ans;
    }
};