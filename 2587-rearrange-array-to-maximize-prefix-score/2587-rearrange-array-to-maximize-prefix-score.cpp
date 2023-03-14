class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        long long curr,prev;
        prev=nums[0];
        int ans=prev>0;
        for(int i=1;i<n;i++){
            curr=prev+nums[i];
            if(curr>0)
                ans++;
            prev=curr;
            
        }
        return ans;
        
        
    }
};