class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=1;
        unordered_map<int,int> um;
        for(int i=0;i<arr.size();i++){
            if(um.find(arr[i]-difference)!=um.end()){
                um[arr[i]]=um[arr[i]-difference]+1;
                ans=max(ans,um[arr[i]]);
            }
            else{
                um[arr[i]]=1;
            }
        }
        return ans;
    }
};