class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        double sum=0.0;
        double avg=0.0;
        int left=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        avg=(double)sum/k;
        ans=max(ans,avg);
        for(int i=k;i<nums.size();i++){
            sum-=nums[left++];
            sum+=nums[i];
            avg=sum/k;
            ans=max(avg,ans);
        }
        return ans;
        
        
    }
};