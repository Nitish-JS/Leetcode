class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int currMin=arr[0];
        int profit=INT_MIN;
        for(int i=0;i<arr.size();i++){
            currMin=min(arr[i],currMin);
            profit=max(profit,arr[i]-currMin);
        }
        return profit;
    }
};