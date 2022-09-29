class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-1;
        while(right-left>=k){
            if(abs(arr[right]-x)<abs(arr[left]-x)){
                left++;
            }
            else{
                right--;
            }
        }
        vector<int> ans;
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};