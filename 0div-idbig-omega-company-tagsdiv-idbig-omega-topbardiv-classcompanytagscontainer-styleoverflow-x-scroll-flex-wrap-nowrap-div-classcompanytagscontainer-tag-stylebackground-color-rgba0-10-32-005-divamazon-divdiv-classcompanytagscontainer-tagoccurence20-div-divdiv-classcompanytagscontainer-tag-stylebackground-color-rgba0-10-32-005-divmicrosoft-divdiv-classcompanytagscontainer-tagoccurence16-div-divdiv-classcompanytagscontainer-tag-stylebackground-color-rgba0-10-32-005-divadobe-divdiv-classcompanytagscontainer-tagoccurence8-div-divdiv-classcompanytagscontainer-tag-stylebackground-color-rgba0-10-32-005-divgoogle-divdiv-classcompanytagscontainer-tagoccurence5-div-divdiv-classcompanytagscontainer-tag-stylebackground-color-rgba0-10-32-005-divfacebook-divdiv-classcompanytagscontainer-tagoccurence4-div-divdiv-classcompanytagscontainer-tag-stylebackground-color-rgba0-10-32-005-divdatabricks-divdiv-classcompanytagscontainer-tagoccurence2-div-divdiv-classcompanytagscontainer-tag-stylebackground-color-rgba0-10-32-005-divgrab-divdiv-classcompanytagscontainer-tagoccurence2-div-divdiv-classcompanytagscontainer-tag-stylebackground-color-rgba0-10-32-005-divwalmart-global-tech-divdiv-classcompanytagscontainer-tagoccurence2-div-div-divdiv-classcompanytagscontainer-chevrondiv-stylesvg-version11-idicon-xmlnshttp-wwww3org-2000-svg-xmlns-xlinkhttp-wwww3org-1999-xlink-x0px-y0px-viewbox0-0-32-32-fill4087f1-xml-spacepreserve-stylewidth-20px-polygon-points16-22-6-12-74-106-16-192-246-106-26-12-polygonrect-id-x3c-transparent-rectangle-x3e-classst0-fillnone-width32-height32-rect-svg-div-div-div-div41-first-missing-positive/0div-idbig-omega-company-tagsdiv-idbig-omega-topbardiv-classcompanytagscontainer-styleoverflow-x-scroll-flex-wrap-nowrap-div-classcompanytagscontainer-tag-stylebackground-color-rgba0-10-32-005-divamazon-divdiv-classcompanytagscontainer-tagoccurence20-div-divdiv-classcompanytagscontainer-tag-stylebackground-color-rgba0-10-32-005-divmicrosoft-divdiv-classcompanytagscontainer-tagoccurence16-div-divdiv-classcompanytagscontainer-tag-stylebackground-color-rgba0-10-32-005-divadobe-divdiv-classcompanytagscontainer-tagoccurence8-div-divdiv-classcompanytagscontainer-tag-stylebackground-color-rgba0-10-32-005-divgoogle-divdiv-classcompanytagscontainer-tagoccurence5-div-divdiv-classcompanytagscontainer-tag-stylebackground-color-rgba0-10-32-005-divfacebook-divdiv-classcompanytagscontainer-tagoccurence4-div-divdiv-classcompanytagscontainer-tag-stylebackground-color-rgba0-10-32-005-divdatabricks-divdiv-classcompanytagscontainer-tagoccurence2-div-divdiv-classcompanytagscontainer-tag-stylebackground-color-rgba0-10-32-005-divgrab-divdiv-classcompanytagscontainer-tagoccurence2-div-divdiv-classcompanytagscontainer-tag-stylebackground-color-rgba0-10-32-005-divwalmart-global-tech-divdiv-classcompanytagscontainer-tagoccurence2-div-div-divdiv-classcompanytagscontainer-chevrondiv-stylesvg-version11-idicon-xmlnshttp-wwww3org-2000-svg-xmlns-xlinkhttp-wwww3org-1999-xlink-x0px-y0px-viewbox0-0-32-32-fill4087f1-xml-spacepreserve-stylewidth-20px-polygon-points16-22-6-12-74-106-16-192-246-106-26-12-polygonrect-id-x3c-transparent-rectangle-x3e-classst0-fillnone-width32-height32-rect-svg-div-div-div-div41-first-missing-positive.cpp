class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> um;
        int mod=1e9;
        for(int i:nums){
            um[i]=1;
        }
        for(int i=1;i<mod;i++){
            if(um.find(i)==um.end())
                return i;
        }
        return mod;
    }
};