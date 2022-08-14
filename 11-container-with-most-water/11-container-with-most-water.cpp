class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        int max_area=min(arr[i],arr[j])*(j-i);
        while(i<j){
            if(arr[i]<arr[j]){
                    i++;
                
            }
            else{
                    j--;
            }
            max_area=max(min(arr[i],arr[j])*(j-i),max_area);
        }
        return max_area;
    }
};