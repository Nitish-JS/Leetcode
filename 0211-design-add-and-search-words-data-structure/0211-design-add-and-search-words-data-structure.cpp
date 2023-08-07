class Node{
public:
    Node* links[26];
    bool flag;
    Node(){
        for(auto &a:links) a=NULL;
        flag=false;
    }
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void insertKey(char c,Node *node){
        links[c-'a']=node;
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }
    Node* getKey(char c){
        return links[c-'a'];
    }
    
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->insertKey(word[i],new Node());
            }
            node=node->getKey(word[i]);
        }
        node->setEnd();
    }
    bool searchNode(string word,int index,Node* node){
        if(index==word.size())
            return node->isEnd();
        if(word[index]=='.'){
            for(char c='a';c<='z';c++){
                if(node->containsKey(c)){
                    if(searchNode(word,index+1,node->getKey(c)))
                        return true;
                }
            }
            return false;
        }
        else{
            if(!node->containsKey(word[index]))
                return false;
            return searchNode(word,index+1,node->getKey(word[index]));
        }
    }
    bool search(string word) {
      return searchNode(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */