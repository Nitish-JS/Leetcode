class Solution {
public:
    bool isPrime(int n){
        if(n<=1)
            return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i][i])){
                maxi=max(maxi,nums[i][i]);
            }
            if(isPrime(nums[i][nums.size()-i-1])){
                maxi=max(maxi,nums[i][nums.size()-i-1]);
            }
        }
        return maxi;
    }
};