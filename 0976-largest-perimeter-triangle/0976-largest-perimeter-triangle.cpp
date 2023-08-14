class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int first=nums[i];
            int second=nums[i+1];
            int third=nums[i+2];
            if(first+second>third){
                ans=max(ans,first+second+third);
            }
        }
        return ans;
    }
};