class Solution {
public:
    void heapify(vector<int> &nums,int largest,int n){
        int index=largest;
        int left=2*index+1;
        int right=2*index+2;
        if(left<n && nums[largest]<nums[left])
            largest=left;
        if(right<n && nums[largest]<nums[right])
            largest=right;
        if(index!=largest){
            swap(nums[largest],nums[index]);
            heapify(nums,largest,n);
        }
      
    }
    int deleteHeap(vector<int> &nums){
        int ans=nums[0];
        nums[0]=nums.back();
        nums.pop_back();
        heapify(nums,0,nums.size());
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int start=n/2;
        for(int i=start;i>=0;i--){
            heapify(nums,i,n);
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=deleteHeap(nums);
        }
        return ans;
    }
};