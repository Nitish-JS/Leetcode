class Solution {
public:
   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    visited[i]=1;
                    q.pop();
                    for(int j=0;j<isConnected[node].size();j++){
                        if(isConnected[node][j]==1 && visited[j]==0){
                            q.push(j);
                            visited[j]=1;                    
                        }
                    }
                }
            }
        }
        return ans;
    }
};