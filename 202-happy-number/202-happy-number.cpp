class Solution {
public:
    int next(int n){
        int ans=0;
        while(n){
            int rem=n%10;
            ans+=rem*rem;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow;
        int fast;
        slow=fast=n;
        do{
            slow=next(slow);
            fast=next(next(fast));
            if (fast==1) return true;
        }while(slow!=fast);
        if(slow==1)
            return true;
        else
            return false;
    }
};