class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1;
                int high=n-1;
                while(low<high){
                    if(nums[i]+nums[low]+nums[high]==0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.clear();
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[i]+nums[low]+nums[high]<0)
                        low++;
                    else
                        high--;
                }
            }
            
        }
        return ans;
        
    }
};