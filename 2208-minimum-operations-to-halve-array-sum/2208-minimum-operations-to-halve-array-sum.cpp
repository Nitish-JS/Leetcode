class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long totalSum=0;
        priority_queue<float> pq;
        for(auto it:nums){
            totalSum+=it;
            pq.push(it);
        }
        int ans=0;
        double currentSum=(double)totalSum/2.0;
        while(currentSum>0)
        {
            double top=pq.top();
            pq.pop();
            top/=2.0;
            currentSum-=top;
            if(top>0)
                pq.push(top);
            ans++;
            // cout<<currentSum<<" "<<totalSum<<"\n";
        }
        return ans;
    }
};