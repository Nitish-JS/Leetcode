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
    bool inorder(TreeNode *root,long low,long high){
        if(!root)
            return true;
        bool left=inorder(root->left,low,root->val);
        if(!(root->val>low && root->val<high))
            return false;
        bool right=inorder(root->right,root->val,high);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        long low=LONG_MIN;
        long high=LONG_MAX;
        return inorder(root,low,high);
    }
};