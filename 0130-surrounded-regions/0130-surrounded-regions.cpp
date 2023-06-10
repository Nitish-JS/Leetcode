class Solution {
public:
    void dfs(vector<vector<int>> &visited,vector<vector<char>> &board,int row,int col){
        int m=visited.size();
        int n=visited[0].size();
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int newRow=row+dirX[i];
            int newCol=col+dirY[i];
            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && board[newRow][newCol]=='O' && visited[newRow][newCol]==0)
                dfs(visited,board,newRow,newCol);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(visited,board,0,i);
            }
            if(board[m-1][i]=='O'){
                cout<<board[m-1][i]<<"\n";
                dfs(visited,board,m-1,i);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dfs(visited,board,i,0);
            if(board[i][n-1]=='O')
                dfs(visited,board,i,n-1);
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<visited[i][j]<<" ";
        //     cout<<"\n";
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0)
                    board[i][j]='X';
            }
        }
    }
};