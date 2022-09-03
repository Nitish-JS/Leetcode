class Solution {
public:
    vector<int> ans;
    int no_of_digit(int n){
        int count=0;
        while(n>0){
            count++;
            n/=10;
        }
        return count;
    }
    void findNumber(int num,int n,int k){
        if(no_of_digit(num)==n){
            ans.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            int last_digit=num%10;
            if(abs(last_digit-i)==k){
                int number=num*10+i;
                findNumber(number,n,k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            findNumber(i,n,k);
        }
        return ans;
    }
};