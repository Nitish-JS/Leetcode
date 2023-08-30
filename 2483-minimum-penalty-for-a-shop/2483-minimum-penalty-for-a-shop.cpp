class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefix(n);
        prefix[0]=customers[0]=='Y'?1:-1;
        for(int i=1;i<n;i++){
            if(customers[i]=='Y'){
                prefix[i]=1+prefix[i-1];
            }
            else{
                prefix[i]=prefix[i-1]-1;
            }
        }
        bool flag=false;
        int index=0;
        int maxTillNow=0;
        for(int i=0;i<n;i++){
            if(prefix[i]>maxTillNow){
                flag=true;
                index=i;
                maxTillNow=prefix[i];
            }
        }
        return flag?index+1:index;
        // return index;
    }
};