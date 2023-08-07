class Node{
public:
    Node* links[26];
    bool end;
    Node(){
        for(auto &a:links) a=NULL;
        end=false;
    }
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    Node* getKey(char c){
        return links[c-'a'];
    }
    void insertKey(char c,Node* node){
        links[c-'a']=node;
    }
    void setEnd(){
        end=true;
    }
    bool isEnd(){
        return end;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
               node->insertKey(word[i],new Node()); 
            node=node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node=node->getKey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
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