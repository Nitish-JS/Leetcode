class Solution {
public:
    bool isCycle(vector<vector<int>> &graph,vector<int> &visited,vector<int> &dfsVisited,int node){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                if(isCycle(graph,visited,dfsVisited,it)==true)
                    return true;
            }
            else if(dfsVisited[it])
                return true;
        }
        dfsVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> visited(n);
        vector<int> dfsVisited(n);
        for(int i=0;i<n;i++){
            if(isCycle(graph,visited,dfsVisited,i)==false)
                ans.push_back(i);
        }
        return ans;
    }
};