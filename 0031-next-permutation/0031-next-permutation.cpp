class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int breakpoint=-1;
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                breakpoint=i-1;
                break;                
            }
        }
        if(breakpoint==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>arr[breakpoint]){
                swap(arr[breakpoint],arr[i]);
                reverse(arr.begin()+breakpoint+1,arr.end());
                break;
            }
        }
        
        
    }
};