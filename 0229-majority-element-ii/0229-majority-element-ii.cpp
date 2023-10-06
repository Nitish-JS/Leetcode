class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=-1,candidate2=-1;
        int vote1=0,vote2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(vote1==0 && nums[i]!=candidate2){
                candidate1=nums[i];
                vote1++;
            }
            else if(vote2==0 && nums[i]!=candidate1){
                candidate2=nums[i];
                vote2++;
            }
            else if(nums[i]==candidate1)
                vote1++;
            else if(nums[i]==candidate2)
                vote2++;
            else{
                vote1--;
                vote2--;
            }
        }
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1)
                count1++;
            else if(nums[i]==candidate2)
                count2++;
        }
        vector<int> ans;
        if(count1>n/3)
            ans.push_back(candidate1);
        if(count2>n/3)
            ans.push_back(candidate2);
        return ans;
    }
};