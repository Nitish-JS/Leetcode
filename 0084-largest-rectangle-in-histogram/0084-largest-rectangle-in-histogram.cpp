class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(st.empty())
                leftSmaller[i]=0;
            else
                leftSmaller[i]=st.top()+1;
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
            if(st.empty())
                rightSmaller[i]=n-1;
            else
                rightSmaller[i]=st.top()-1;
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max((rightSmaller[i]-leftSmaller[i]+1)*heights[i],ans);
        }
        return ans;
    }
};