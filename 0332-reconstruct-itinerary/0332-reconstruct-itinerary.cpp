class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string start=st.top();
            if(adj[start].size()==0){
                ans.push_back(start);
                st.pop();
            }
            else{
                auto dest=adj[start].begin();
                st.push(*dest);
                adj[start].erase(dest);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};