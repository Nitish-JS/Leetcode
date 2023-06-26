class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> left;
        priority_queue<int,vector<int>,greater<int>> right;
        int nextLeft=candidates;
        int nextRight=n-candidates-1;
        for(int i=0;i<candidates;i++){
            left.push(costs[i]);
        }
        
        for(int i=max(candidates,n-candidates);i<n;i++){
            right.push(costs[i]);
        }
        for(int i=0;i<k;i++){
            if(right.empty() || (!left.empty() && left.top()<=right.top())){
                ans+=left.top();
                left.pop();
                if(nextLeft<=nextRight){
                    left.push(costs[nextLeft]);
                    nextLeft++;
                }
            }
            else{
                ans+=right.top();
                right.pop();
                if(nextLeft<=nextRight){
                    right.push(costs[nextRight]);
                    nextRight--;
                }
            }
        }
        return ans;
    }
};