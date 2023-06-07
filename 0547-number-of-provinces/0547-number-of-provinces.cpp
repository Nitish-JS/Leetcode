class Solution {
public:
    void bfs(vector<vector<int>> &isConnected,vector<int> &visited,int start){
        queue<int> q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<isConnected[node].size();i++){
                if(isConnected[node][i]==1 && visited[i]==0){
                    q.push(i);
                    visited[i]=1;                    
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                bfs(isConnected,visited,i);
            }
        }
        return ans;
    }
};