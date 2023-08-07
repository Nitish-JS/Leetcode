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
    Node *getKey(char c){
        return links[c-'a'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }
    
};

class Trie {
public:
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->insertKey(word[i],new Node());
            }
            node=node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
               return false;
            }
            node=node->getKey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
               return false;
            }
            node=node->getKey(word[i]);
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