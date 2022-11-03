class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> um;
        for(auto s:words){
            um[s]++;
        }
        int ans=0;
        for(auto it:um){
            string rev=it.first;
            reverse(rev.begin(),rev.end());
            cout<<it.first<<" "<<rev<<" ";
            if(rev==it.first){
                int y=it.second;
                if(y%2!=0)
                    y--;
                ans+=2*y;
                um[it.first]-=y;
            }
            else if(um.find(rev)!=um.end()){
                int mini=min(it.second,um[rev]);
                ans+=4*mini;
                um[rev]-=mini;
                um[it.first]-=mini;
            }
            cout<<ans<<'\n';
        }
        for(auto it:um){
            int count=it.second;
            string rev=it.first;
            reverse(rev.begin(),rev.end());
            if(rev==it.first && count>0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};