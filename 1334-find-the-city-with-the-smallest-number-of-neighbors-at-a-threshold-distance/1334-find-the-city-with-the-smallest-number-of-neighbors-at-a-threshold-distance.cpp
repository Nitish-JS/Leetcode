class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n,1e8));
        for(auto it:edges){
            graph[it[0]][it[1]]=it[2];
            graph[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)
            graph[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int ans;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int noOfCity=0;
            for(int j=0;j<n;j++){
                if(graph[i][j]<=distanceThreshold){
                    noOfCity++;
                }
            }
            // cout<<noOfCity<<"\n";
            if(noOfCity<=mini){
                ans=i;
                mini=noOfCity;
                
            }
        }
        
        return ans;
        
    }
};