class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++){
            um[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<int> visited(n);
        q.push(0);
        visited[0]=1;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                if(curr==n-1){
                    return steps;
                }
                vector<int> &list=um[arr[curr]];
                list.push_back(curr-1);
                list.push_back(curr+1);
                for(int next:list){
                    if(next>=0 && next<n && !visited[next]){
                        q.push(next);
                        visited[next]=1;
                    }
                }
                list.clear();
            }
            steps++;
        }
        return -1;
    }
};