class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> st;
        for(int i:nums){
            st.insert(i);
        }
        int ans=1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};