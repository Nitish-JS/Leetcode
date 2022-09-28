class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<right && arr[left]<=arr[left+1] ){
            left++;
        }
        if(left==n-1)
            return 0;
        while(arr[right]>=arr[right-1] &&  right>0){
            right--;
        }
        ans=min(n-left-1,right);
        int i=0,j=right;
       for(int i=0;i<=left;i++){
           if(arr[i]<=arr[right])
               ans=min(ans,right-i-1);
           else if(right<n-1)
               right++;
           else
               break;
       }
        return ans;
    }
};