class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        int max_area=min(arr[i],arr[j])*(j-i);
        while(i<j){
            int current_area;
            if(arr[i]<arr[j]){
                    i++;
                current_area=min(arr[i],arr[j])*(j-i);
            }
            else{
                    j--;
               current_area=min(arr[i],arr[j])*(j-i);
            }
            max_area=max(current_area,max_area);
        }
        return max_area;
    }
};