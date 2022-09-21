class Solution {
public:
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int evenSum=0;
        for(int i:nums){
            if(!(i&1))
                evenSum+=i;
        }
        for(auto it:queries){
            int val=it[0],index=it[1];
            int oldValue=nums[index];
            nums[index]+=val;
            bool wasEven=!(oldValue&1);
            bool isEven=!(nums[index]&1);
            if(wasEven && isEven){
                evenSum+=val;
            }
            else if(wasEven && !isEven){
                evenSum-=oldValue;
            }
            else if(!wasEven && isEven){
                evenSum+=nums[index];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};