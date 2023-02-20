class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> mini(n);
        vector<int> maxi(n);
        maxi[n-1]=nums[n-1];
        mini[0]=nums[0];
        for(int i=1;i<n;i++){
            mini[i]=min(mini[i-1],nums[i]);
            maxi[n-i-1]=max(maxi[n-i],nums[n-i-1]);
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>mini[i-1] && nums[i]<maxi[i+1])
                return true;
        }
        return false;
    }
};