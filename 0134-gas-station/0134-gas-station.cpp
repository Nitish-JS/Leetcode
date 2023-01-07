class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int max_gas=0,max_cost=0;
        int curr_gas=0,curr_cost=0;
        int start=0;
        for(int i=0;i<n;i++){
            max_gas+=gas[i];
            max_cost+=cost[i];
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                start=i+1;
                curr_gas=0;
                
            }
        }
        return (max_gas<max_cost)?-1:start;
    }
};