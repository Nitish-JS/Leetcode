class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1;
                int high=nums.size()-1;
                while(low<high){
                    if(nums[i]+nums[low]+nums[high]==0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
                    temp.clear();
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(high>low && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[i]+nums[low]+nums[high]<0){
                        low++;
                    }
                    else{
                        high--;
                    }   
                }
            }

        }
        return ans;
    }
};