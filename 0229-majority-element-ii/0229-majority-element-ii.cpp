class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=-1,vote1=0;
        int candidate2=-1,vote2=0;
        for(int i:nums){
            if(vote1==0 && i!=candidate2){
                candidate1=i;
                vote1=1;
            }
            else if(vote2==0 && i!=candidate1){
                candidate2=i;
                vote2=1;
            }
            else if(candidate1==i)
                vote1++;
            else if(candidate2==i)
                vote2++;
            else{
                vote1--;
                vote2--;
            }
             // cout<<candidate1<<" "<<candidate2<<'\n';
        }
        int count1=0,count2=0;
        for(int i:nums){
            if(i==candidate1)
                count1++;
            else if(i==candidate2)
                count2++;
            
        }
       
        vector<int> ans;
        if(count1>nums.size()/3)
            ans.push_back(candidate1);
        if(count2>nums.size()/3)
            ans.push_back(candidate2);
        return ans;
    }
};