class DisjointSet{
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(x==parent[x])
            return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionByRank(int u,int v){
        int ultimate_parent_u=findParent(u);
        int ultimate_parent_v=findParent(v);
        if(ultimate_parent_u==ultimate_parent_v)
            return ;
        if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_v]<rank[ultimate_parent_u]){
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]+=1;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet DS(n);
        vector<int> ans;
        for(auto edge:edges){
            int ultimate_parent_u=DS.findParent(edge[0]);
            int ultimate_parent_v=DS.findParent(edge[1]);
            if(ultimate_parent_u==ultimate_parent_v){
                if(ans.size()!=0){
                     ans.pop_back();
                }
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }
            else{
                DS.unionByRank(edge[0],edge[1]);
            }
       
        }
         return ans;
    }
};