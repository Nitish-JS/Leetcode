class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(parent[x]==x)
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
    void unionByRank(int u,int v){
        int ultimate_parent_u=findParent(u);
        int ultimate_parent_v=findParent(v);
        if(ultimate_parent_u==ultimate_parent_v)
            return ;
        if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if (rank[ultimate_parent_u]>rank[ultimate_parent_v]){
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DisjointSet dsu(n);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                
                int d1=abs(x1-x2);
                int d2=abs(y1-y2);
                int dist=d1+d2;
                edges.push_back({dist,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        int ans=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(dsu.findParent(u)!=dsu.findParent(v)){
                ans+=wt;
                dsu.unionBySize(u,v);
            }
        }
        return ans;
    }
    
};