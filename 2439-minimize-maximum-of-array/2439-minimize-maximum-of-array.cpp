class Solution {
public:
    bool valid(int mid,vector<int> &nums){
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>((long)mid)*(i+1)) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low=0;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};