class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       int n=arr.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<n-1 && arr[left]<=arr[left+1]  ){
            left++;
        }
        if(left==n-1)
            return 0;
        while(right>left && arr[right]>=arr[right-1]  ){
            right--;
        }
        ans=min(n-left-1,right);
        int i=0,j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};