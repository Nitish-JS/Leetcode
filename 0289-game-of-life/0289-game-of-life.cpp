class Solution {
void countLiveNeighbours(vector<vector<int>> &boards,int row,int col,vector<vector<int>> &neighbours){
    // cout<<row<<" "<<col<<" \n";
    int count=0;
    int m=boards.size();
    int n=boards[0].size();
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0 && j==0)
                continue;
            int nextRow=row+i;
            int nextCol=col+j;
            // cout<<nextRow<<" "<<nextCol<<" \n"; 
            if(nextRow>=0 && nextCol>=0 && nextRow<m && nextCol<n && boards[nextRow][nextCol]==1)
                count++;
                
        }
    }
    neighbours[row][col]=count;
    
}
public:
    void gameOfLife(vector<vector<int>>& boards) {
        int m=boards.size();
        int n=boards[0].size();
        vector<vector<int>> neighbours(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                countLiveNeighbours(boards,i,j,neighbours);
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<neighbours[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(boards[i][j]==1){
                    if(neighbours[i][j]<2)
                        boards[i][j]=0;
                    else if(neighbours[i][j]>3)
                        boards[i][j]=0;
                }
                else{
                    if(neighbours[i][j]==3)
                        boards[i][j]=1;
                }
            }
        }
    }
};