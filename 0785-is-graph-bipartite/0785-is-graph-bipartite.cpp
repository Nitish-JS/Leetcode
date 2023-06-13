class Solution {
public:
    bool dfsColor(vector<vector<int>> &graph,vector<int> &colorArr,int start,int color){
        colorArr[start]=color;
        for(auto it:graph[start]){
            if(colorArr[it]==-1){
                if(dfsColor(graph,colorArr,it,!color)==false)
                    return false;
            }
            else if(colorArr[it]==color)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it]==-1){
                            q.push(it);
                            color[it]=!color[node];
                        }
                        else if(color[it]==color[node])
                            return false;
                    }
                }
            }
                // if(dfsColor(graph,color,i,0)==false)
                //     return false;
                
        }
        return true;
    }
};