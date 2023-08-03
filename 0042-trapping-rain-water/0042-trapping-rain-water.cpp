class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> prefix(n,height[0]);
        vector<int> suffix(n,height[n-1]);
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],height[i]);
            suffix[n-i-1]=max(suffix[n-i],height[n-i-1]);
        }
        for(int i=0;i<n;i++){
            ans+=min(prefix[i],suffix[i])-height[i];
        }
        return ans;
    }
};