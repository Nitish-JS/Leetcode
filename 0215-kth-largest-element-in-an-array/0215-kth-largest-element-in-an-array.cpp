class Solution {
public:
    void heapify(vector<int> &nums,int index,int n){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<n && nums[left]>nums[largest])
            largest=left;
        if(right<n && nums[right]>nums[largest])
            largest=right;
        if(largest!=index){
            swap(nums[largest],nums[index]);
            heapify(nums,largest,n);
        }
    }
    int deleteHeap(vector<int> &nums){
        int val=nums[0];
        nums[0]=nums.back();
        nums.pop_back();
        heapify(nums,0,nums.size());
        return val;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int start=n/2-1;
        for(int i=start;i>=0;i--)
            heapify(nums,i,n);
        // for(int i:nums)
        //     cout<<i<<" ";
        int ans=0;
        for(int i=0;i<k;i++)
            ans=deleteHeap(nums);
        return ans;
    }
};