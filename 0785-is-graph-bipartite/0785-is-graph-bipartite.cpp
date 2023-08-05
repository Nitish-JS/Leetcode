class Solution {
public:
    // dfs approach
    // bool check(vector<vector<int>> &graph,vector<int> &colors,int node,int color){
    //     colors[node]=color;
    //     for(auto it:graph[node]){
    //         if(colors[it]==-1){
    //             if(check(graph,colors,it,!color)==false)
    //                 return false;
    //         }
    //         else if(colors[it]==colors[node])
    //             return false;
    //     }
    //     return true;
    // }
    
    
    // bfs approach
    
    bool check(vector<vector<int>> &graph,vector<int> &colors,int node,int color){
        colors[node]=color;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(colors[it]==-1){
                    colors[it]=!colors[node];
                    q.push(it);
                }
                else if(colors[it]==colors[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(check(graph,colors,i,0)==false)
                    return false;
            }
        }
        return true;
    }
};