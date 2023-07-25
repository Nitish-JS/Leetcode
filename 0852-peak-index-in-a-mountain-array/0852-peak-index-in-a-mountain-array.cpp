class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int ans=-1;
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==0 ){
                if( arr[mid]>arr[mid+1])
                    return mid;
                else
                    low=mid+1;
            }
            else if(mid==arr.size()-1){
                if( arr[mid]>arr[mid-1])
                    return mid;
                else
                    high=mid-1;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
                low=mid+1;
            else 
                high=mid-1;
        }
        return -1;
    }
};