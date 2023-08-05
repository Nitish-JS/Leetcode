class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> mat(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=image[i][j];
            }
        }
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        int startColor=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            pair<int,int> currNode=q.front();
            int row=currNode.first;
            int col=currNode.second;
            mat[row][col]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=row+dirX[i];
                int newCol=col+dirY[i];
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && mat[newRow][newCol]==startColor && mat[newRow][newCol]!=color){
                    q.push({newRow,newCol});
                }
            }
        }
        return mat;
    }
};