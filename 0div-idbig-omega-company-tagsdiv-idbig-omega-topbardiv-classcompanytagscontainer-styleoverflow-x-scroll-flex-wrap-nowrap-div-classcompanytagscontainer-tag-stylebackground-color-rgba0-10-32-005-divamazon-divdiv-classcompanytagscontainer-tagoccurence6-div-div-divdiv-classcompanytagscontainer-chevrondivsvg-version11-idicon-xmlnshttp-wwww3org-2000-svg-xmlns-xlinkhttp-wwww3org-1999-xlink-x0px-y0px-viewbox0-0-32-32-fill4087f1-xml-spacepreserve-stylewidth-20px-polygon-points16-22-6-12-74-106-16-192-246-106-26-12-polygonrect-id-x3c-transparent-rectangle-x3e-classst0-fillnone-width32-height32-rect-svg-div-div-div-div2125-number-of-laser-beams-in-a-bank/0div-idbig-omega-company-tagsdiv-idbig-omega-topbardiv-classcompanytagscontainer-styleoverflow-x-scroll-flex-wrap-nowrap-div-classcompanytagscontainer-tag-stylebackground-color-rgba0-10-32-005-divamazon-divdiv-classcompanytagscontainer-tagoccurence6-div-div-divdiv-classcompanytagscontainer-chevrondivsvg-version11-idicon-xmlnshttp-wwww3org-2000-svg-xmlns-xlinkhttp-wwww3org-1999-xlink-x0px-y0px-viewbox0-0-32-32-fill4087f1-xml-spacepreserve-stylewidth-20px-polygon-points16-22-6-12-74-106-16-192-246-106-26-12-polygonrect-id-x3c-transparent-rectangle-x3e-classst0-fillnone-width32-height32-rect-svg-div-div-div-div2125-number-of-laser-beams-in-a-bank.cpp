class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=-1;
        int curr=-1;
        int ans=0;
        int m=bank.size();
        int n=bank[0].size();
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1')
                    count++;
            }
            if(count>0){
                prev=curr;
                curr=count;
            }
            // cout<<prev<<" "<<curr<<"\n";
            if(prev>0 && curr>0 && count>0){
               ans+=prev*curr;
            }
        }
        return ans;
    }
};