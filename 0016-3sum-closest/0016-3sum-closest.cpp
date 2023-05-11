class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1;
                int high=n-1;
                while(low<high){
                    int cur=nums[i]+nums[low]+nums[high];
                    if(cur==target)
                        return cur;
                    if(abs(target-cur)<abs(target-ans))
                        ans=cur;
                    if(cur>target)
                        high--;
                    else
                        low++;
                    
                }
            }
        }
        return ans;
    }
};