class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u)
            return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionBySize(int u,int v){
        int ulti_parent_u=findParent(u);
        int ulti_parent_v=findParent(v);
        if(ulti_parent_u==ulti_parent_v)
            return ;
        if(size[ulti_parent_u]<size[ulti_parent_v]){
            parent[ulti_parent_u]=ulti_parent_v;
            size[ulti_parent_v]+=size[ulti_parent_u];
        }
        else{
            parent[ulti_parent_v]=ulti_parent_u;
            size[ulti_parent_u]+=size[ulti_parent_v];
        }
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        DisjointSet dsu(n);
        for(int i=0;i<n;i=i+2){
            dsu.unionBySize(row[i],row[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i=i+2){
            if(dsu.findParent(i)!=dsu.findParent(i+1)){
                ans++;
                dsu.unionBySize(i,i+1);
            }
        }
        return ans;
    }
};