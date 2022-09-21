class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int> &permArray,vector<int> &nums,vector<int> &freq){
        if(permArray.size()==nums.size()){
            ans.push_back(permArray);
            return;        
        }
        for(int i=0;i<nums.size();i++){
            // if()
            if(!freq[i]){
                permArray.push_back(nums[i]);
                freq[i]=1;
                permute(permArray,nums,freq);
                permArray.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> freq(nums.size());
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        // map<vector<int>,bool> um;

        // sort(nums.begin(),nums.end());
        vector<int> permArray;
        permute(permArray,nums,freq);
        set<vector<int>> s;
        for(auto it:ans){
            s.insert(it);
        }
        ans.clear();
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
        
    }
    
};