class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board){
        int n=board.size();
        int rowtemp=row;
        int coltemp=col;
        for(int i=col;i>=0;i--){
            if(board[row][i]=='Q') return false;
        }
        while(rowtemp>=0 && coltemp>=0){
            if(board[rowtemp--][coltemp--]=='Q') return false;
        }
        while(row<n && col>=0){
            if(board[row++][col--]=='Q') return false;
        }
        return true;
    }
    
    void solve(int &ans,vector<string> &board,int col,int n){
        if(col==n){
            ans++;
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                solve(ans,board,col+1,n);
                board[row][col]='.';
            }
        }
        
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,board,0,n);
        return ans;
    }
};