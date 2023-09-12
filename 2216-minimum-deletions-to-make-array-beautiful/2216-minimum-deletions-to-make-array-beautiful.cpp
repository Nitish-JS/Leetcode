class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if( !(i&1) && nums[i]==nums[i+1] && flag ){
                ans++;
                flag=false;
            }
            else if( (i&1) && nums[i]==nums[i+1] && !flag){
                ans++;
                flag=true;
            }
        }
        if((n-ans)&1)
            ans++;
        return ans;
    }
};