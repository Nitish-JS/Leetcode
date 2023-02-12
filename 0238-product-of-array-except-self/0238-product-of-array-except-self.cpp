class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
            suf[n-i-1]=suf[n-i]*nums[n-i];
        }
        suf[0]=suf[1]*nums[1];
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(pre[i]*suf[i]);
        return ans;
    }
};