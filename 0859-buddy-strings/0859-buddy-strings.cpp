class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        int diff1=INT_MIN,diff2=INT_MIN;
        set<char> characterSet;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                if(diff1==INT_MIN)
                    diff1=i;
                else if(diff2==INT_MIN)
                    diff2=i;
                else
                    return false;
            }
            characterSet.insert(s[i]);
        }
        if(diff1!=INT_MIN && diff2!=INT_MIN)
            return s[diff1]==goal[diff2] && s[diff2]==goal[diff1];
        if(diff1!=INT_MIN )
            return false;
        return characterSet.size()<s.size();
            
    }
};