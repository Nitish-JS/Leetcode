class Solution {
public:
    int solve(vector<int> &nums,int left,int right,int chance){
        if(left>right)
            return 0;
        if(chance==0)
            return min(solve(nums,left+1,right,1),solve(nums,left,right-1,1));
        else
            return max(nums[left]+solve(nums,left+1,right,0),nums[right]+solve(nums,left,right-1,0));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int alice=0;
        int bob=0;
        for(int i:nums)
            bob+=i;
        alice=solve(nums,0,nums.size()-1,1);
        bob-=alice;
        cout<<alice<<" "<<bob<<'\n';

        return alice>=bob;
    }
};