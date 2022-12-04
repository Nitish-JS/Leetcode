class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        
        for(int i=0;i<n;i++){
            if(i!=0){
                prefix[i]=prefix[i-1]+nums[i];
                suffix[n-i-1]=nums[n-i-1]+suffix[n-i];
            }else{
                prefix[0]=nums[i];
                suffix[n-1]=nums[n-1];
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
                int diff=abs((prefix[i]/(i+1)-suffix[i+1]/(n-i-1)));
                if(diff<ans){
                    index=i;
                    ans=diff;
                }
            }
        }
            
        return index;
    }
};