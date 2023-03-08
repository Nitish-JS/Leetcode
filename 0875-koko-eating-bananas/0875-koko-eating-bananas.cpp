class Solution {
public:
    bool canEat(vector<int> &piles,int mid,int h){
        long ans=0;
        for(int i:piles){
            ans+=i/mid;
            if(i%mid!=0) 
                ans++;
            
        }
        return ans<=h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=1e9;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canEat(piles,mid,h)) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};