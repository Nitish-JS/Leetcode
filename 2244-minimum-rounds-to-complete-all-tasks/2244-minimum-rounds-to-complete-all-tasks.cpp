class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            int temp=it.second;
            if(temp==1)
                return -1;
            if(temp%3==0)
                ans+=temp/3;
            else 
                ans+=temp/3+1;
        }
        return ans;
    }
};