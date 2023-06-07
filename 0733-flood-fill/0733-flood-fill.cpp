class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial=image[sr][sc];
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        image[sr][sc]=color;
        // doing bfs
        while(!q.empty()){
            pair<int,int> node=q.front();
            int currRow=node.first;
            int currCol=node.second;
            q.pop();
            if(currRow-1>=0 && currRow-1<n && !visited[currRow-1][currCol] && image[currRow-1][currCol]==initial){
                q.push({currRow-1,currCol});
                visited[currRow-1][currCol]=1;
                image[currRow-1][currCol]=color;
            }
            if(currRow+1>=0 && currRow+1<n && !visited[currRow+1][currCol] && image[currRow+1][currCol]==initial){
                q.push({currRow+1,currCol});
                visited[currRow+1][currCol]=1;
                image[currRow+1][currCol]=color;
            }
            if(currCol-1>=0 && currCol-1<m && !visited[currRow][currCol-1] && image[currRow][currCol-1]==initial){
                q.push({currRow,currCol-1});
                visited[currRow][currCol-1]=1;
                image[currRow][currCol-1]=color;
            }
            if(currCol+1>=0 && currCol+1<m && !visited[currRow][currCol+1] && image[currRow][currCol+1]==initial){
                q.push({currRow,currCol+1});
                visited[currRow][currCol+1]=1;
                image[currRow][currCol+1]=color;
            }
        }
        return image;
    }
};