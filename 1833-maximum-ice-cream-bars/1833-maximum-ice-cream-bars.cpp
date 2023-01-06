class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        while(coins>=0 && ans<costs.size()){
            if(costs[ans]<=coins){
                coins=(coins-costs[ans])%100000000;
                ans++;
            }       
            else return ans;
        }
        return ans;
    }
};