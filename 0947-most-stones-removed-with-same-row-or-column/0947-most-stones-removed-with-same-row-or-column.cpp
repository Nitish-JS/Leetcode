class DisjointSet{
    vector<int> parent,size;
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(it[0],maxRow);
            maxCol=max(it[1],maxCol);
        }
        DisjointSet DS(maxRow+maxCol+1);
        unordered_map<int,int> um;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            DS.unionBySize(nodeRow,nodeCol);
            um[nodeRow]=1;
            um[nodeCol]=1;
        }
        int ans=0;
        for(auto it:um){
            if(it.first==DS.findParent(it.first))
                ans++;
        }
        return n-ans;
    }
};