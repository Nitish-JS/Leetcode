class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        for(int i=0;i<n;i++){
            if(i!=0){
                prefix[i]=prefix[i-1]+nums[i];
               
            }else{
                prefix[0]=nums[i];
            }
        }
        int index=-1;
        long long ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(prefix[i]/(n)<ans)
                    index=i;
            }
            else{
                int diff=abs((prefix[i]/(i+1)-(prefix[n-1]-prefix[i])/(n-i-1)));
                if(diff<ans){
                    index=i;
                    ans=diff;
                }
            }
        }
        return index;
    }
};