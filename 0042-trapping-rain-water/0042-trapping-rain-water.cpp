class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(),height[0]);
        vector<int> suffix(height.size(),height[height.size()-1]);
        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);
            suffix[height.size()-i-1]=max(height[height.size()-i-1],suffix[height.size()-i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(prefix[i],suffix[i])-height[i];
        }
        return ans;
        
    }
};