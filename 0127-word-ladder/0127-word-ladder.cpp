class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        
        while(!q.empty()){
            pair<string,int> node=q.front();
            q.pop();
            string word=node.first;
            int steps=node.second;
            if(word==endWord)
                return steps;
            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
        
    }
};