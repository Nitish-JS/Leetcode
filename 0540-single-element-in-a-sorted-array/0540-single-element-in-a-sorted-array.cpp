class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
       
        int low=0,high=arr.size()-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid%2==1){
                if(arr[mid-1]==arr[mid])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else{
                if(arr[mid+1]==arr[mid])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return arr[low];
        
    }
};