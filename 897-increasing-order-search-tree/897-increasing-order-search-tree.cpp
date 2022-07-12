/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(vector<int> &nodes,TreeNode* root){
        if(!root)
            return ;
        inOrder(nodes,root->left);
        nodes.push_back(root->val);
        inOrder(nodes,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(nodes,root);
        TreeNode *newTree=new TreeNode(nodes[0]);
        TreeNode *temp=newTree;
        for(int i=1;i<nodes.size();i++){
            TreeNode *newNode=new TreeNode(nodes[i]);
            temp->right=newNode;
            temp=temp->right;
        }
        return newTree;
        
    }
};