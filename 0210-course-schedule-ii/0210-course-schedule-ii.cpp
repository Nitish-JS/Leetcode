class Solution {
public:
    bool isCyclic(vector<int> adj[],vector<int> &visited,vector<int> &dfsVisited,int node,stack<int> &st){
        visited[node]=1;
        dfsVisited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(isCyclic(adj,visited,dfsVisited,it,st))
                    return true;
            }
            else if(dfsVisited[it])
                return true;
        }
        st.push(node);
        dfsVisited[node]=0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> visited(n);
        vector<int> dfsVisited(n);
        stack<int> st;
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(isCyclic(adj,visited,dfsVisited,i,st)==true)
                    return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;     
    }
};