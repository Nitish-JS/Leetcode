// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      
        for(int i=n;i>0;i--){
            if(isBadVersion(i)){
                if(!isBadVersion(i-1))
                    return i;
            }
           
        }
        return NULL;   
        
    }
};