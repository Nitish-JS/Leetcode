class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            int count=0;
            int temp=i;
            while(temp){
                temp=temp&(temp-1);
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};