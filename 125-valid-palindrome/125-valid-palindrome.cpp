class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(char c:s){
            if(isalnum(c))
                pal+=tolower(c);
        }
        int i=0,j=pal.size()-1;
        while(i<j){
            if(pal[i]!=pal[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};