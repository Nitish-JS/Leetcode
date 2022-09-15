class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int minimum=INT_MAX;
        int max_profit=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<minimum)
                minimum=arr[i];
            max_profit=max(max_profit,arr[i]-minimum);
        }
        return max_profit;
    }
};