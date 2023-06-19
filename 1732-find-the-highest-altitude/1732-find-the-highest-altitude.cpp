class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int altitude=0;
        int ans=0;
        for(int i=0;i<gain.size();i++){
            altitude+=gain[i];
            ans=max(ans,altitude);
        }
        return ans;
        
    }
};