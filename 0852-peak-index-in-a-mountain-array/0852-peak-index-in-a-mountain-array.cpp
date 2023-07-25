class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        int size=arr.size();
        for(int i=1;i<size-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                ans=i;
                    
        }   
        return ans;
    }
};