class Solution {
public:
    bool solve(vector<vector<char>> &board,string &word,int i,int j,int wordIndex){
        int n=board.size();
        int m=board[0].size();
        if(wordIndex==word.size())
            return true;
        if(i<0 || j<0|| i>=n || j>=m || board[i][j]=='*' || board[i][j]!=word[wordIndex]) 
            return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool up=solve(board,word,i-1,j,wordIndex+1);
        bool down=solve(board,word,i+1,j,wordIndex+1);
        bool right=solve(board,word,i,j+1,wordIndex+1);
        bool left=solve(board,word,i,j-1,wordIndex+1);
        board[i][j]=temp;
        return up || down|| right||left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && solve(board,word,i,j,0) ){
                    return true;
                }
                
            }
        }
        return false;
    }
};