class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                        int low=j+1;
                        int high=nums.size()-1;
                        while(low<high){
                            if((long)nums[i]+nums[j]+nums[low]+nums[high]==target){
                                ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                                while(low<high && nums[low]==nums[low+1]) low++;
                                while(high>low && nums[high]==nums[high-1]) high--;
                                low++;
                                high--;
                            }
                            else if((long)nums[i]+nums[j]+nums[low]+nums[high]<target)
                                low++;
                            else
                                high--;
                        }
                    }
                }
            }
        }
        // vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};