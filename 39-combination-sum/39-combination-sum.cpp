class Solution {
public:
    vector<vector<int>> ans;
    void combination(int index,int target,vector<int> &arr,vector<int> &ds){
        if(index==arr.size() || target==0){
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            combination(index,target-arr[index],arr,ds);
            ds.pop_back();
        }
        combination(index+1,target,arr,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> ds;
        combination(0,target,arr,ds);
        return ans;
    }
};