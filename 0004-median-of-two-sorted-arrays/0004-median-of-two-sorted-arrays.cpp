class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        int n=nums1.size(),m=nums2.size();
        vector<int> merged(n+m);
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                merged[k++]=nums1[i++];
            }
            else
                merged[k++]=nums2[j++];
        }
        while(i<n){
            merged[k++]=nums1[i++];
        }
        while(j<m)
            merged[k++]=nums2[j++];
        double median=0.0;
        if((m+n)%2==0){
            median=(double)(merged[(m+n)/2]+merged[(m+n)/2-1])/(double)2;
        }
        else{
            // cout<<"no";
            median=merged[(m+n)/2];
        }
        return median;
        
    }
};