class Solution {
public:
    bool detectCapitalUse(string word) {
       int caps=0;
        for(int i=0;i<word.size();i++){
           if((int)word[i]>=65 && (int)word[i]<=91)
                caps++;
        }
        if(caps==word.size() || caps==1 && ((int)word[0]>=65 && (int)word[0]<=91) || caps==0)
            return true;
        else 
            return false;
    }
};