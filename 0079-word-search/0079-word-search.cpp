class Solution {
public:
    bool solve(vector<vector<char>> &board,string &word,int wordIdx,int i,int j){
        if(wordIdx==word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='*' || board[i][j]!=word[wordIdx])
            return false;
        // if(dp[i][j]!=-1)
        //     return dp[i][j];
        char temp=board[i][j];
        board[i][j]='*';
        bool up=solve(board,word,wordIdx+1,i-1,j);
        bool down=solve(board,word,wordIdx+1,i+1,j);
        bool left=solve(board,word,wordIdx+1,i,j-1);
        bool right=solve(board,word,wordIdx+1,i,j+1);
        board[i][j]=temp;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> dp(board.size(),vector<int>(board[0].size(),-1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && solve(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
    
};