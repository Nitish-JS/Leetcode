class Solution {
public:
    
//     DFS Approach
//     bool solve(vector<int> graph[],vector<int> &visited,int node,vector<int> &arr){
//         visited[node]=1;
//         if(arr[node]==0)
//             return true;
//         for(auto it:graph[node]){
//             if(!visited[it]){
//                 if(solve(graph,visited,it,arr)==true)
//                     return true;
//             }
//         }
//         return false;
       
//     }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> graph[n];
        for(int i=0;i<n;i++){
            if(i+arr[i]<n && arr[i]!=0)
                graph[i].push_back(i+arr[i]);
            if(i-arr[i]>=0 && arr[i]!=0)
                graph[i].push_back(i-arr[i]);
        }

        vector<int> visited(n,0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(arr[node]==0){
                return true;
            }
            visited[node]=1;
            for(auto it:graph[node]){
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
        return false;
        // return solve(graph,visited,start,arr);
        
    }
};