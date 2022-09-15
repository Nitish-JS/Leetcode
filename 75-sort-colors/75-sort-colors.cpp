class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count=0,one_count=0,two_count=0;
        for(int i:nums){
            if(i==0)
                zero_count++;
            else if(i==1)
                one_count++;
            else
                two_count++;
        }
        int index=0;
        while(zero_count){
            nums[index++]=0;
            zero_count--;
        }
        while(one_count){
            nums[index++]=1;
            one_count--;
        }
        while(two_count){
            nums[index++]=2;
            two_count--;
        }
    }
};