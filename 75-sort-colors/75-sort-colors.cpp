class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& arr) {
        int low=0,mid=0,high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[high],arr[mid]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
};