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
    bool solve(TreeNode *root){
        if(!root)
            return false;
        bool lsolve=solve(root->left);
        bool rsolve=solve(root->right);
        if(!lsolve)
            root->left=NULL;
        if(!rsolve)
            root->right=NULL;
        return root->val==1 || lsolve || rsolve;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        bool ans=solve(root);
        if(!ans)
            return NULL;
        return root;
    }
};