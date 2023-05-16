class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board){
        int n=board.size();
        int rowTemp=row;
        int colTemp=col;
        // check same row
        for(int i=col;i>=0;i--){
            if(board[row][i]=='Q')
                return false;
        }
        //check upper diagonal
        while(rowTemp>=0 && colTemp>=0){
            if(board[rowTemp--][colTemp--]=='Q')
                return false;
        }
        //check lower diagonal
        while(row<n && col>=0){
            if(board[row++][col--]=='Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string>&board,int col,int n){
        if(col==n){
            ans.push_back(board);
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,board,0,n);
        return ans;
        
    }
};