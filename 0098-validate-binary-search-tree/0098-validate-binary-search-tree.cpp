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
    bool inOrder(TreeNode *root,long low,long high){
        if(!root)
            return true;
        bool left=inOrder(root->left,low,root->val);
        if(root->val<=low || root->val>=high)
            return false;
        bool right=inOrder(root->right,root->val,high);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return inOrder(root,LONG_MIN,LONG_MAX);
    }
};