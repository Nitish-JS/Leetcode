class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr1_last=m-1;
        int arr2_last=n-1;
        int merged_last=n+m-1;
        while(arr1_last>=0 && arr2_last>=0){
            if(nums2[arr2_last]>nums1[arr1_last]){
                nums1[merged_last]=nums2[arr2_last];
                arr2_last--;
                merged_last--;
            }
            else{
                nums1[merged_last]=nums1[arr1_last];
                arr1_last--;
                merged_last--;
            }
        }
        while(arr1_last>=0){
            nums1[merged_last]=nums1[arr1_last];
                arr1_last--;
                merged_last--;
        }
        while(arr2_last>=0){
            nums1[merged_last]=nums2[arr2_last];
                arr2_last--;
                merged_last--;
        }
    }
};