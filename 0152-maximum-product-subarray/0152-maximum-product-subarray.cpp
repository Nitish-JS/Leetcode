class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_till_now=1,min_till_now=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int mul1=max_till_now*nums[i];
            int mul2=min_till_now*nums[i];
            max_till_now=max(nums[i],max(mul1,mul2));
            min_till_now=min(nums[i],min(mul1,mul2));
            ans=max(max_till_now,ans);
        }
        return ans;
    }
};