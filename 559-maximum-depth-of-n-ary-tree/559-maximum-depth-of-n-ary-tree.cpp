/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    int maxDepth(Node* root) {
        if(root){
            int maxi=1;
            for(auto child:root->children){
                maxi=max(maxi,maxDepth(child)+1);
            }
            return maxi;
        }
        return 0;
        
        
    }
        
};