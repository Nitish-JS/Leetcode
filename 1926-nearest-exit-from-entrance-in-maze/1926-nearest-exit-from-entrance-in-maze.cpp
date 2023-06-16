class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        int step=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> currPos=q.front();
                int currRow=currPos.first;
                int currCol=currPos.second;
                q.pop();
                if((currRow==n-1 || currCol==m-1 || currRow==0 || currCol==0) && (currRow!=entrance[0]||currCol!=entrance[1]))
                    return step;
                for(int i=0;i<4;i++){
                    int nextRow=currPos.first+dirX[i];
                    int nextCol=currPos.second+dirY[i];
                    if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m && visited[nextRow][nextCol]==-1 && maze[nextRow][nextCol]=='.'){
                        q.push({nextRow,nextCol});
                        visited[nextRow][nextCol]=1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};