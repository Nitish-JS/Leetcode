class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            int ele=asteroids[i];
            if(st.empty() || ele>0){
                st.push(ele);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(ele)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(ele)){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top()<0)
                        st.push(ele);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
};