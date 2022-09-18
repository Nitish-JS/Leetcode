class Solution {
public:
    vector<vector<int>> ans;
    void combination(int index,int target,vector<int> &arr,vector<int> &ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            combination(i+1,target-arr[i],arr,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        combination(0,target,candidates,ds);
        return ans;
    }
};