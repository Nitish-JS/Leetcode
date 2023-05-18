class Solution {
public:
    void heapify(vector<string> &nums,int n,int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<n && nums[left].size()==nums[largest].size()){
            for(int i=0;i<nums[left].size();i++){
                if(nums[left][i]!=nums[largest][i]){
                    if((nums[left][i])-'0'>(nums[largest][i])-'0')
                        largest=left;
                    break;
                }
            }
        }else{
            if(left<n && nums[left].size()>=nums[largest].size())
            largest=left;
        }
        
        if(right<n && nums[right].size()==nums[largest].size()){
            for(int i=0;i<nums[right].size();i++){
                if(nums[right][i]!=nums[largest][i]){
                    if((nums[right][i])-'0'>(nums[largest][i])-'0')
                        largest=right;
                    break;
                }
               
            }
        }
        else{
            if(right<n && nums[right].size()>=nums[largest].size())
            largest=right;
        }       
        if(largest!=index){
            swap(nums[largest],nums[index]);
            heapify(nums,n,largest);
        }
    }
    string deleteFromHeap(vector<string> &nums){
        string ans=nums[0];
        nums[0]=nums.back();
        nums.pop_back();
        heapify(nums,nums.size(),0);
        return ans;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        int startIndex=n/2-1;
        for(int i=startIndex;i>=0;i--){
            heapify(nums,n,i);
        }
        string ans;
        for(int i=0;i<k;i++){
            ans=deleteFromHeap(nums);
            // cout<<ans<<"\n";
        }
        return ans;
    }
};