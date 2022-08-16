class Solution {
public:
    char repeatedCharacter(string s) {
       set<char> chars;
        for(int i=0;i<s.size();i++){
            if(chars.find(s[i])==chars.end()){
                chars.insert(s[i]);
            }
            else
                return s[i];
        }
        return NULL;
    }
};