class Solution {
public:
    vector<vector<int>> ans;
    void combination(int index,int target,vector<int> &arr,vector<int> &ds,int k){
        if(ds.size()==k){
            if(target==0){
                ans.push_back(ds);
                return ;
            }
        }
        for(int i=index;i<arr.size();i++){
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            combination(i+1,target-arr[i],arr,ds,k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<10;i++){
            nums.push_back(i);
        }
        vector<int> ds;
        combination(0,n,nums,ds,k);
        return ans;
    }
};