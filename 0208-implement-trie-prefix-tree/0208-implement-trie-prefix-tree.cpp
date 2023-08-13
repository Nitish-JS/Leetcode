class Node{
    Node *links[26];
    bool endWord;
    public:
    Node(){
        for(auto &a:links) a=NULL;
        endWord=false;
    }
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void insertChar(char c,Node* newNode){
        links[c-'a']=newNode;
    }
    Node* getLink(char c){
        return links[c-'a'];
    }
    void setEndWord(){
        endWord=true;
    }
    bool isEndWord(){
        return endWord;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                node->insertChar(word[i],new Node());
            node=node->getLink(word[i]);
        }
        node->setEndWord();
        
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node=node->getLink(word[i]);
        }
        return node->isEndWord();
    }
    
    bool startsWith(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node=node->getLink(word[i]);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */