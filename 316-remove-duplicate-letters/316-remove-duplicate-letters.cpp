class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,bool> visited;
        stack<char> st;
        string res="";
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            freq[s[i]]--;
            if(!visited[s[i]]){
                while(st.size()>0 && st.top()>s[i] && freq[st.top()]>0){
                  visited[st.top()]=false;
                    st.pop();
                } 
                st.push(s[i]);
                visited[s[i]]=true;
            }
        }
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
        
    }
};