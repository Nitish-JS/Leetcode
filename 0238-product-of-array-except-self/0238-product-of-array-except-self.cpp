class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=1;
        // for(int i=1;i<n;i++){
        //     val=left*nums[i-1];
        //     left=val;
        //     val=right*nums[n-i];
        //     right=val;
        //     ans.push_back(nums)
        // }
        // right[0]=right[1]*nums[1];
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=left;
            left*=nums[i];
            ans[n-1-i]*=right;
            right*=nums[n-1-i];
        }
        

        return ans;
    }
};