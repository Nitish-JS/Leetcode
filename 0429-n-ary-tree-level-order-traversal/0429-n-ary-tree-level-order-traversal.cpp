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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> level;
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                for(auto child:root->children){
                    q.push(child);
                }
                level.push_back(root->val);
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};