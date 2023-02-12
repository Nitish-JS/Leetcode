class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    // cout<<"entering\n";
                    words.push_back(temp);
                    
                }
                temp="";
                continue;
            }
            else{
                temp+=s[i];
            }
        }
        words.push_back(temp);
        temp="";
        for(int i=words.size()-1;i>=0;i--){
            if(words[i]=="")
                continue;
            temp=temp+words[i];
            if(i!=0)
                temp+=" ";
        }
        return temp;
    }
};