class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int,int> um;
        int i=1;
        um[i]=1;
        int j=1;
        while(true){
            um[(j+i*k)%n]++;
            j+=(i*k%n);
            i++;
            if(um[(j+i*k)%n])
                break;
            
        }
        for(auto it:um){
            cout<<it.first<<" "<<it.second<<'\n';
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(um.find(i%n)==um.end())
                ans.push_back(i);
        }
        return ans;
    }
};