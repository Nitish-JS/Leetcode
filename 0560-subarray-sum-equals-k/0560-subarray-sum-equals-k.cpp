class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int prefix=0;
        um[prefix]=1;
        int ans=0;
        for(auto i:nums){
            prefix+=i;
            ans+=um[prefix-k];
            um[prefix]++;
            
        }
        return ans;
    }
};