class DisjointSet{
    
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(x==parent[x])
            return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionBySize(int u,int v){
        int ultimate_parent_u=findParent(u);
        int ultimate_parent_v=findParent(v);
        if(ultimate_parent_u==ultimate_parent_v)
            return ;
        if(size[ultimate_parent_u]<size[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // building disjoint set
        DisjointSet DS(n*n+1);
        int dirX[]={-1,0,1,0};
        int dirY[]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) 
                    continue;
                for(int k=0;k<4;k++){
                    int nextRow=i+dirX[k];
                    int nextCol=j+dirY[k];
                    if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<n && grid[nextRow][nextCol]==1){
                        int currCellNo=i*n+j;
                        int nextCellNo=nextRow*n+nextCol;
                        DS.unionBySize(currCellNo,nextCellNo);
                    }
                }
            }
        }
        // traversing
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int currMax=0;
                    set<int> components;
                    for(int k=0;k<4;k++){
                        int nextRow=i+dirX[k];
                        int nextCol=j+dirY[k];
                        if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<n && grid[nextRow][nextCol]==1){
                            int nextCellNo=nextRow*n+nextCol;
                            components.insert(DS.findParent(nextCellNo));
                        }
                    }
                    for(auto it:components){
                        currMax+=DS.size[it];
                    }
                    ans=max(currMax+1,ans);
                }
            }
        }
        //handling all one case
        for(int cell=0;cell<n*n;cell++){
            ans=max(ans,DS.size[DS.findParent(cell)]);
        }
        return ans;
    }
};