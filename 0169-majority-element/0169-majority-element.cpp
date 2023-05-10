class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int candidate=-1,vote=0;
        for(int i=0;i<nums.size();i++){
            if(vote==0){
                candidate=nums[i];
                vote=1;
            }
            else if(nums[i]==candidate)
                vote++;
            else
                vote--;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]=candidate){
                count++;
            }
        }
        return count>nums.size()/2?candidate:-1;
    }
};