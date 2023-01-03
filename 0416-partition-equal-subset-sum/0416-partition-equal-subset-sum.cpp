class Solution {
public:
//     bool solve(int n, int k, vector<int> &arr) {
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0)
            return false;
        sum/=2;
        vector<bool> prev(sum+1,false);
        vector<bool> curr(sum+1,false);
        prev[0]=true;
        curr[0]=true;
        for(int index=1;index<nums.size();index++){
            for(int target=1;target<=sum;target++){
                bool take=false;
                if(nums[index]<=target){
                    take=prev[target-nums[index]];
                }
                bool nottake=prev[target];
                curr[target]=take||nottake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};