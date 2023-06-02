class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> row1={{'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1}};
        unordered_map<char,int> row2={{'a',1},{'s',1},{'d',1},{'f',1},{'g',1},{'h',1},{'j',1},{'k',1},{'l',1}};
        unordered_map<char,int> row3={{'z',1},{'x',1},{'c',1},{'v',1},{'b',1},{'n',1},{'m',1}};
        vector<string> ans;
        for(string word:words){
            int c1=0,c2=0,c3=0;
            for(char c:word){
                if(row1.find(tolower(c))!=row1.end())
                    c1++;
                else if(row2.find(tolower(c))!=row2.end())
                    c2++;
                else
                    c3++;
            }
            if(c1==word.size())
                ans.push_back(word);
            else if(c2==word.size())
                ans.push_back(word);
            else if(c3==word.size())
                ans.push_back(word);
        }
        return ans;
    }
};