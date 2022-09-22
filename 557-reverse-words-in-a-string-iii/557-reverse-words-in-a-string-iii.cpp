class Solution {
public:
    string reverseWords(string s) {
        vector<string> strings;
        int i=0;
        string temp="";
        for(int i=0;i<=s.size();i++){
            
            
            if(s[i]==' ' || i==s.size()){
                strings.push_back(temp);
                temp="";
                continue;
            }
            temp+=s[i];
        }
        string ans="";
        for(string word:strings){
            for(int i=0;i<word.size()/2;i++){
                char temp=word[i];
                word[i]=word[word.size()-i-1];
                word[word.size()-i-1]=temp;
            }
            ans+=word;
            ans+=" ";
        }
        // str.erase(remove(str.begin(), str.end(), ' '), str.end());
         ans.erase(remove(ans.begin()+ans.size()-1,ans.end(),' '));
        return ans;
    }
};