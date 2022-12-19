class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int maxi=*max_element(nums2.begin(),nums2.end());
        vector<int> nge(maxi+1,-1);
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])
                st.pop();
            if(!st.empty()){
                nge[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};