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
            if(color[i]==-1)
                if(dfsColor(graph,color,i,0)==false)
                    return false;
        }
        return true;
    }
};