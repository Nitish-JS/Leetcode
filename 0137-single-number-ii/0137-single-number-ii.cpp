class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ones=0;
        // int twos=0;
        // for(int i=0;i<nums.size();i++){
        //     ones=ones^nums[i]&(~twos);
        //     twos=twos^nums[i]&(~ones);
        // }
        // return ones;
        int num=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if((1<<i)&nums[j])
                    count++;
            }
            if(count%3){
                num=num|(1<<i);
            }
        }
        return num;
    }
};