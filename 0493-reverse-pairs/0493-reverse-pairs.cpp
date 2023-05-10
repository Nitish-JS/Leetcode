class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        int answer=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>(long)2*nums[j]){
                j++;
            }
            answer+=(j-(mid+1));
        }
        int left=low;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid && right <=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return answer;
        
    }
    int mergeSort(vector<int> &nums,int low,int high){
        if(low>=high)
            return 0;
        int answer=0;
        int mid=low+(high-low)/2;
        answer+=mergeSort(nums,low,mid);
        answer+=mergeSort(nums,mid+1,high);
        answer+=merge(nums,low,mid,high);
        return answer;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};