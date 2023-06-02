class Solution {
public:
//     int solve(int index,int prev,vector<int>&nums,vector<vector<int>> &dp){
//         if(index>=nums.size())
//             return 0;
//         if(dp[index][prev+1]!=-1)
//             return dp[index][prev+1];
//         int pick=0;
//         if(prev==-1 || nums[index]>nums[prev])
//             pick=1+solve(index+1,index,nums,dp);
//         int notpick=0+solve(index+1,prev,nums,dp);
//         return dp[index][prev+1]=max(pick,notpick);
        
//     }
    int lowerBound(vector<int> &arr,int k){
        int low=0;
        int high=arr.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(k<=arr[mid])
                high=mid;
            else
                low=mid+1;
        }
        if(low<arr.size() && arr[low]<k)
            low++;
        return low;
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<arr[i])
                temp.push_back(arr[i]);
            else{
                int index=lowerBound(temp,arr[i]);
                temp[index]=arr[i];
            }
        }
        return temp.size();
        // int n=arr.size();
        // int dp[n];
        // fill(dp,dp+n,1);
        // int maxi=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(arr[j]<arr[i]){
        //             dp[i]=max(dp[i],1+dp[j]);
        //         }
        //     }
        // }
        // for(int i:dp){
        //     maxi=max(maxi,i);
        // }
        // return maxi;
       //  vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
       // return solve(0,-1,nums,dp);
    }
};