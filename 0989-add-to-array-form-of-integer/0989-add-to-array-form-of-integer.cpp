class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            int arraynum=num[i];
            int rem=k%10;
            k/=10;
            int total=arraynum+rem+carry;
            num[i]=total%10;
            carry=total/10;
        }
        while(k>0){
            int total=k%10+carry;
            num.insert(num.begin(),total%10);
            carry=total/10;
            k/=10;
        
        }
        if(carry){
            num.insert(num.begin(),carry);
        }
        return num;
    }
};