class DisjointSet{
public:
    vector<int> parent,rank,size;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
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
            return; 
        if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_u]){
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else{
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]+=1;
        }  
    }
    void unionBySize(int u,int v){
        int ultimate_parent_u=findParent(u);
        int ultimate_parent_v=findParent(v);
        if(ultimate_parent_u==ultimate_parent_v)
            return; 
        if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
     
        DisjointSet DS(n);
        unordered_map<string,int> um;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(um.find(mail)==um.end()){
                    um[mail]=i;
                }
                else{
                    DS.unionBySize(i,um[mail]);
                }
                
            }
        }
        vector<string> mergeMail[n];
        for(auto it:um){
            mergeMail[DS.findParent(it.second)].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergeMail[i].begin(),mergeMail[i].end());
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};