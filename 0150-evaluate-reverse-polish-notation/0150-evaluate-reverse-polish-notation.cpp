class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        long ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                long b=st.top();
                st.pop();
                long a=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    ans=a+b;
                    st.push(ans);
                }
                else if(tokens[i]=="-"){
                    ans=a-b;
                    st.push(ans);
                }
                else if(tokens[i]=="*"){
                    ans=a*b;
                    st.push(ans);
                }
                else{
                    ans=a/b;
                    st.push(ans);
                }
                
            }
            else{
                st.push(stoi(tokens[i]));
            }
            
        }
        return st.top();
    }
};