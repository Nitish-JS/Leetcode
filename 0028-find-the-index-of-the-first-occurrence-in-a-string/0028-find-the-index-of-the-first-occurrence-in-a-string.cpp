class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle.size()==0)
           return -1;
        int i=0,j=0;
        while(i<haystack.size() and j<needle.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size()){
                    return i-needle.size();
                }
            }
            else{
                i=i-j+1;                
                j=0;
            }
            

        }
        return -1;
    }
};