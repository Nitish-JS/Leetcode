class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m=arr.size();
        int n=arr[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int midValue=arr[mid/n][mid%n];
            if(midValue==target)
                return true;
            else if(midValue<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
        
    }
};