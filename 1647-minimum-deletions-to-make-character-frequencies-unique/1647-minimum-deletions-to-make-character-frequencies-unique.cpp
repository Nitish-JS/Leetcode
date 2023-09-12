class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> um;
        for(char c:s){
            um[c]++;
        }
        priority_queue<int> pq;
        for(auto it:um){
            // cout<<it.first<<" "<<it.second<<" ";
            pq.push(it.second);
        }
        int ans=0;
        while(pq.size()!=1){
            int max=pq.top();
            pq.pop();
            // cout<<max<<" "<<pq.top()<<"\n"; 
            if(max==pq.top() && max!=0){
                ans++;
                pq.push(max-1);
            }
        }
        return ans;
        
    }
};