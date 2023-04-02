class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            int low=0,high=potions.size()-1;
            int index;
            long long num=spells[i];
            while(low<=high){
                int mid=low+(high-low)/2;
                if(num*potions[mid]>=success){
                    high=mid-1;
                   index=mid;
                }
                else{
                    low=mid+1;
                }
            }
            if(low>=potions.size())
                ans.push_back(0);
            else
                ans.push_back(potions.size()-index);
        }
        return ans;
    }
};