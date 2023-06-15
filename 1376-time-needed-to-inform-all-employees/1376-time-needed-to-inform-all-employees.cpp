class Solution {
public:
    // int maxTime=INT_MIN;
    // void dfs(vector<int> adj[],vector<int> &informTime,int curr,int time ){
    //     maxTime=max(time,maxTime);
    //     for(auto it:adj[curr]){
    //         dfs(adj,informTime,it,time+informTime[curr]);
    //     }
    // }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        // dfs(adj,informTime,headID,0);
        int maxTime=INT_MIN;
        int time=0;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty()){
            int currManager=q.front().first;
            int time=q.front().second;
            q.pop();
            maxTime=max(time,maxTime);
            for(auto it:adj[currManager]){
                q.push({it,time+informTime[currManager]});
            }
        }
        return maxTime;
    }
};