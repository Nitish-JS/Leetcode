class Solution {
public:
    
    int numTrees(int n) {
        if(n==1)
            return 1;
        int k=n;
        n=n*2;
      long long ans;
        for(int i=0;i<k;i++){
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
        return ans/(k+1);
        
    }
};