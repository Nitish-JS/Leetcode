class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int mod=1e9+7;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                for(int j=i+1;j<n;j++){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                        int low=j+1;
                        int high=n-1;
                        while(low<high){
                            long long tar1=nums[low];
                            long long tar2=nums[high];
                            long long tar3=nums[i];
                            long long tar4=nums[j];
                            if(tar1+tar2+tar3+tar4==target){
                                temp.push_back(nums[i]);
                                temp.push_back(nums[j]);
                                temp.push_back(nums[low]);
                                temp.push_back(nums[high]);
                                ans.push_back(temp);
                                temp.clear();
                                while(low<high && nums[low]==nums[low+1]) low++;
                                while(low<high && nums[high]==nums[high-1]) high--;
                                low++;
                                high--;
                            }
                            else if(tar1+tar2+tar3+tar4<target)
                                low++;
                            else
                                high--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};